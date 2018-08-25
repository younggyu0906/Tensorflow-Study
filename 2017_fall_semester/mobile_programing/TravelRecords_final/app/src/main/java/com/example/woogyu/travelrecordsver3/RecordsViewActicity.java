package com.example.woogyu.travelrecordsver3;

import android.content.Intent;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteException;
import android.graphics.drawable.ColorDrawable;
import android.net.Uri;
import android.support.v7.app.ActionBar;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.support.v7.widget.Toolbar;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.TextView;

import org.w3c.dom.Text;

public class RecordsViewActicity extends AppCompatActivity {
    private static final int CHANGE = 2;
    private Uri photoUri;

    //DB객체
    DBHelper helper;
    SQLiteDatabase db;

    TextView title;
    TextView memo;
    TextView loc;
    TextView date;
    TextView spot;
    ImageView imgMain;

    String time;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_records_view_acticity);

        //액션바 설정
        Toolbar toolBar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolBar);
        ActionBar actionBar = getSupportActionBar();
        actionBar.setBackgroundDrawable(new ColorDrawable(0xFFFF4081));

        //디비 생성 및 불러오기
        helper = new DBHelper(this);
        try {
            db = helper.getWritableDatabase();
        }catch (SQLiteException ex){
            db = helper.getReadableDatabase();
        }

        time = getIntent().getStringExtra("TIME");

        imgMain = (ImageView)findViewById(R.id.view_records);
        title = (TextView)findViewById(R.id.view_title);
        memo = (TextView)findViewById(R.id.view_memo);
        loc = (TextView)findViewById(R.id.view_loc);
        date = (TextView)findViewById(R.id.view_date);
        spot = (TextView)findViewById(R.id.view_spot);

        settings(getIntent().getStringExtra("URI"));
    }

    public void settings(String uri){
        photoUri = Uri.parse(uri);
        imgMain.setImageURI(null);
        imgMain.setImageURI(photoUri);

        Cursor cursor = db.rawQuery("SELECT title, memo, loc, date, spot FROM records WHERE uri='"+uri+"';",null);

        cursor.moveToFirst();
        title.setText(cursor.getString(0));
        memo.setText(cursor.getString(1));
        loc.setText(cursor.getString(2));
        date.setText(cursor.getString(3));
        spot.setText(cursor.getString(4));
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.menu_record_view, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        Cursor cursor;

        int id = item.getItemId();

        if (id == R.id.action_repair) {
            cursor = db.rawQuery("SELECT uri FROM records WHERE time='"+ time +"';",null);
            cursor.moveToFirst();

            Intent intent = new Intent(this,RecordsAddActivity.class);
            intent.putExtra("URI",cursor.getString(0));
            intent.putExtra("SELECT",CHANGE);
            startActivityForResult(intent,0);
        }
        else if(id == R.id.action_exit){
            finish();
        }
        return super.onOptionsItemSelected(item);
    }

    @Override
    protected void onActivityResult(int requstCode, int resultCode, Intent data){
        if(requstCode == 0){
            if(resultCode == RESULT_CANCELED){
                try{
                    time = data.getStringExtra("TIME");
                    settings(data.getStringExtra("URI"));
                }catch (NullPointerException e){

                }
            }
        }
    }
}
