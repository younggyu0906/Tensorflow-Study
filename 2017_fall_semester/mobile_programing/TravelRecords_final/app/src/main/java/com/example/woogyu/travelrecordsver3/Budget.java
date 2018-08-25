package com.example.woogyu.travelrecordsver3;

import android.app.Dialog;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteException;
import android.graphics.drawable.ColorDrawable;
import android.support.v7.app.ActionBar;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.support.v7.widget.Toolbar;
import android.text.TextUtils;
import android.util.Log;
import android.view.ActionMode;
import android.view.ContextMenu;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.EditText;
import android.widget.ListView;
import android.widget.SimpleCursorAdapter;
import android.widget.Toast;

public class Budget extends AppCompatActivity  {
    static final int DIALOG_ID = 1;
    static final int GET_STRING = 10;

    int budgetID = 0;

    int m_pos=0;

    private ActionMode mActionMode;             // 액션모드 객체 선언

    private DBHelper helper;
    private SQLiteDatabase db;
    private Cursor c;

    boolean isScheAdd = false;
    boolean isSelect = false;

    ListView list;

    SimpleCursorAdapter adapter;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_budget);

        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar); //액션바 설정
        setSupportActionBar(toolbar);

        ActionBar actionBar = getSupportActionBar(); //액션바 색깔
        actionBar.setBackgroundDrawable(new ColorDrawable(0xFF9CCC65));

        Intent intent = getIntent();
        if(intent != null) {
            isScheAdd = intent.getBooleanExtra("ISSCHEADD", false);
        }

        // SQLiteOpenHelper 클래스의 subclass인 DBHelper 클래스 객체 생성
        helper = new DBHelper(this);
        // DBHelper 객체를 이용하여 DB 생성
        try {
            db = helper.getWritableDatabase();
        } catch (SQLiteException e) {
            db = helper.getReadableDatabase();
        }

        onSetting();
    }

    @Override
    protected void onStart() {
        super.onStart();

        onSetting();
    }

    public void onSetting() {
        // contacts 테이블에서 모든 레코드를 retrieve
        c = db.rawQuery("SELECT * FROM tbudget;", null);

        if(c.getCount() != 0) {
            c.moveToFirst();
            while(c.moveToNext()) {
                budgetID = c.getInt(1);
            }
            budgetID += 1;
            Log.i("IDCHECK", Integer.toString(budgetID));
        }

        String[] from = {"title", "tcost"};
        int[] to = {android.R.id.text1, android.R.id.text2};
        // SimpleCursorAdapter 객체 생성
        // 하나의 리스트 아이템에 2개의 텍스트뷰를 표시하는 레이아웃
        adapter = new SimpleCursorAdapter(this, android.R.layout.simple_list_item_2, c, from, to);

        // 레이아웃에 정의된 리스트뷰에 대한 참조 객체 얻음
        list = (ListView)findViewById(R.id.bdgtList);
        // 리스트뷰 객체에 어댑터 설정
        list.setAdapter(adapter);

        adapter.notifyDataSetChanged();

        list.setOnItemClickListener(onClickListItem);
        registerForContextMenu(list);
    }

    public boolean isEmpty(EditText et) {
        String st = et.getText().toString();
        if(TextUtils.isEmpty(st)) {
            return true;
        }
        else
            return false;
    }

    @Override
    protected Dialog onCreateDialog(int id) {
        Context mContext = getApplicationContext();
        LayoutInflater inflater = (LayoutInflater) mContext.getSystemService(LAYOUT_INFLATER_SERVICE);
        final View layout = inflater.inflate(R.layout.budget_title,(ViewGroup) findViewById(R.id.btlist));
        switch (id) {
            case DIALOG_ID:
                AlertDialog.Builder builder = new AlertDialog.Builder(this);
                builder.setTitle("예산 이름을 입력하세요.");
                builder.setView(layout);

                EditText etTitle = (EditText)layout.findViewById (R.id.dtbtitle);

                builder.setPositiveButton("Yes", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        EditText etTitle = (EditText)layout.findViewById (R.id.dtbtitle);

                        if(isEmpty(etTitle)) {
                            Toast.makeText(getApplicationContext(), "이름을 입력하세요.", Toast.LENGTH_SHORT).show();
                            return;
                        }

                        String title = etTitle.getText().toString();

                        if(isSame(title)) {
                            Toast.makeText(getApplicationContext(), "같은 이름이 있습니다!", Toast.LENGTH_SHORT).show();
                            return;
                        }

                        db.execSQL("INSERT INTO tbudget VALUES (null, '" + budgetID + "', '" + title + "', '" + 0 + "');");
                        onSetting();
                        Toast.makeText(getApplicationContext(), "예산이름 등록", Toast.LENGTH_SHORT).show();
                    }
                });
                builder.setNegativeButton("No", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        dialog.dismiss();
                    }
                });
                adapter.notifyDataSetChanged();
                AlertDialog alert = builder.create();
                alert.show();
                return alert;
        }
        return null;
    }

    public boolean isSame(String s) {
        try {
            c = db.rawQuery("SELECT * FROM tbudget WHERE title='"+ s + "';", null);
            if(c.getCount() == 0)
                return false;
            else
                return true;
        }catch (NullPointerException e){
            return true;
        }
    }


    // 아이템 터치 이벤트 리스너 구현
    private AdapterView.OnItemClickListener onClickListItem = new AdapterView.OnItemClickListener() {
        @Override
        public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
            Intent intent = new Intent(Budget.this, BudgetInfo.class);
            c = (Cursor)parent.getAdapter().getItem(position);
            String temp = (c.getString(c.getColumnIndex("title")));

            Log.i("IDCHECK", temp);

            c = db.rawQuery("SELECT * FROM tbudget WHERE title='" + temp +"';", null);
//            Log.i("IDCHECK", adapter.getItem(position).toString());
            c.moveToFirst();
            intent.putExtra("BDGTID", c.getInt(1));

            if(intent != null) {
                if(intent.resolveActivity(getPackageManager()) != null) {
                    if(isScheAdd) {
                        intent.putExtra("ISSCHEADD", true);
                        Log.i("tcadd----B_SAFR", "액티비티 시작");
                        startActivityForResult(intent, GET_STRING);
                    }
                    else {
                        intent = new Intent(Budget.this, BudgetInfo2.class);
                        intent.putExtra("BDGTID", c.getInt(1));
                        startActivity(intent);
                    }
                }
            }
        }
    };

    @Override
    protected void onResume() {
        super.onResume();
    }

    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.addeditbar, menu);
        return super.onCreateOptionsMenu(menu);
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        switch(item.getItemId()) {
            case R.id.add_br:
                showDialog(DIALOG_ID);
                return true;
            case R.id.action_exit:
                finish();
            default:
                return super.onOptionsItemSelected(item);
        }
    }

    @Override
    public void onCreateContextMenu(ContextMenu menu, View view, ContextMenu.ContextMenuInfo menuInfo){
        super.onCreateContextMenu(menu,view,menuInfo);
        menu.setHeaderTitle("일정편집");
        menu.setHeaderIcon(R.drawable.ic_album_black_24dp);
        menu.add(0,1,0,"삭제");
        menu.add(0,2,0,"취소");
        m_pos = ((AdapterView.AdapterContextMenuInfo) menuInfo).position;
    }

    public boolean onContextItemSelected(MenuItem item){
        int count;
        count = adapter.getCount();

        switch (item.getItemId()){
            case 1:
                if (count == 0) {
                    Toast.makeText(getApplicationContext(), "삭제할 아이템이 없습니다", Toast.LENGTH_SHORT).show();
                    return false;
                }

                c = (Cursor)list.getAdapter().getItem(m_pos);
                String tmp = (c.getString(c.getColumnIndex("title")));

                c = db.rawQuery("SELECT * FROM tbudget WHERE title='" + tmp + "';", null);
                c.moveToFirst();
                int tmpnum = c.getInt(1);

                db.execSQL("DELETE FROM tbudget WHERE bdgtid='"+ tmpnum + "';");
                db.execSQL("DELETE FROM budget WHERE bdgtid='"+ tmpnum + "';");

                onSetting();
                adapter.notifyDataSetChanged();

                return true;
            default:
                return super.onContextItemSelected(item);
        }
    }

    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        if(requestCode == GET_STRING) {
            if(resultCode == RESULT_OK) {
                isSelect = data.getBooleanExtra("ISSELECT", false);
                int total_cost = data.getIntExtra("TOTALCOST", 0);
                if(isSelect) {
                    //db.execSQL();
                    Intent in = new Intent();
                    in.putExtra("TOTALCOST", total_cost);
                    Log.i("tcadd----B_isSelect", Integer.toString(total_cost));

                    setResult(RESULT_OK, in);
                    finish();
                }
                else
                    Toast.makeText(getApplicationContext(), "예산이 선택되지 않았습니다.", Toast.LENGTH_SHORT).show();
            }
        }
    }
}