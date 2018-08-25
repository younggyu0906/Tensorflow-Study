package com.example.woogyu.travelrecordsver3;

import android.content.Intent;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteException;
import android.graphics.drawable.ColorDrawable;
import android.support.v7.app.ActionBar;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.support.v7.widget.Toolbar;
import android.util.Log;
import android.view.ContextMenu;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.SimpleCursorAdapter;
import android.widget.Toast;

import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;

public class RecordsActivity extends AppCompatActivity implements AdapterView.OnItemClickListener{
    //DB객체
    DBHelper helper;
    SQLiteDatabase db;

    //초기 액티비티
    RecordsActivity recordsActivity;

    private static final int ADD = 1;
    private static final int CHANGE = 2;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_records);

        recordsActivity = this;

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

        settings();
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.menu_records, menu);
        return true;
    }
    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        int id = item.getItemId();

        if(id == R.id.action_add){
            Intent intent = new Intent(this,RecordsAddActivity.class);
            intent.putExtra("SELECT",ADD);
            startActivityForResult(intent,0);
        }
        else if(id == R.id.action_exit){
            finish();
        }
        return super.onOptionsItemSelected(item);
    }

    @Override
    public void onItemClick(AdapterView<?> parent, View view, int position, long id){
        Cursor cursor;
        String time;

        cursor = (Cursor)adapter.getItem(position);
        time = cursor.getString(cursor.getColumnIndex("time"));

        cursor = db.rawQuery("SELECT uri FROM records WHERE time='"+ time +"';",null);
        cursor.moveToFirst();

        Intent intent = new Intent(this,RecordsViewActicity.class);
        intent.putExtra("URI",cursor.getString(0));
        intent.putExtra("TIME",time);
        startActivityForResult(intent,1);
    }

    int nPosition;
    @Override
    public void onCreateContextMenu(ContextMenu menu, View view, ContextMenu.ContextMenuInfo menuInfo){
        super.onCreateContextMenu(menu,view,menuInfo);
        menu.setHeaderTitle("기록편집");
        menu.setHeaderIcon(R.drawable.ic_album_black_24dp);
        menu.add(0,1,0,"수정");
        menu.add(0,2,0,"삭제");
        menu.add(0,3,0,"취소");
        nPosition = ((AdapterView.AdapterContextMenuInfo) menuInfo).position;
    }

    public boolean onContextItemSelected(MenuItem item){

        Cursor cursor;
        String time;

        switch (item.getItemId()){
            case 1:
                cursor = (Cursor)adapter.getItem(nPosition);
                time = cursor.getString(cursor.getColumnIndex("time"));
                cursor = db.rawQuery("SELECT uri FROM records WHERE time='"+ time +"';",null);
                cursor.moveToFirst();

                Intent intent = new Intent(this,RecordsAddActivity.class);
                intent.putExtra("URI",cursor.getString(0));
                intent.putExtra("SELECT",CHANGE);
                startActivityForResult(intent,0);
                return true;
            case 2:
                cursor = (Cursor)adapter.getItem(nPosition);
                time = cursor.getString(cursor.getColumnIndex("time"));

                db.execSQL("DELETE FROM records WHERE time ='"+time+"';");
                startActivity(new Intent(this,RecordsActivity.class));
                recordsActivity.finish();
                return true;
            default:
                return super.onContextItemSelected(item);
        }
    }

    @Override
    protected void onActivityResult(int requstCode, int resultCode, Intent data){
        if(requstCode == 0){
            if(resultCode == RESULT_CANCELED){
                Log.i("Map-->","RESULT CANCELED");
                startActivity(new Intent(this,RecordsActivity.class));
                recordsActivity.finish();
            }
        }
        else if(requstCode == 1){
            startActivity(new Intent(this,RecordsActivity.class));
            recordsActivity.finish();
        }
    }

    SimpleCursorAdapter adapter;
    public void settings(){
        Cursor cursor = db.rawQuery("SELECT * FROM records", null);

        String[] from = {"title", "time"};
        int[] to = {android.R.id.text1, android.R.id.text2};

        adapter = new SimpleCursorAdapter(this,
                android.R.layout.simple_list_item_2, cursor, from, to);

        ListView list = (ListView)findViewById(R.id.list);
        list.setAdapter(adapter);
        list.setOnItemClickListener(this);


        registerForContextMenu(list);
    }
}
