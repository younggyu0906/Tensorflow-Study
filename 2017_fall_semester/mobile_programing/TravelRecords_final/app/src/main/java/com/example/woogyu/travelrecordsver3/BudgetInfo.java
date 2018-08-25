package com.example.woogyu.travelrecordsver3;

import android.app.Dialog;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteException;
import android.graphics.drawable.ColorDrawable;
import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.v7.app.ActionBar;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.text.TextUtils;
import android.util.Log;
import android.view.ContextMenu;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.EditText;
import android.widget.ListView;
import android.widget.SimpleCursorAdapter;
import android.widget.TextView;
import android.widget.Toast;

/**
 * Created by WooJin on 2017-12-20.
 */

public class BudgetInfo extends AppCompatActivity {

    ListView list;
    private DBHelper DBHelper;
    private SQLiteDatabase bdgt_db;
    private Cursor c;
    private int budgetID = 0;
    private int total_cost = 0;
    SimpleCursorAdapter adapter;

    TextView tv;

    int m_pos = 0;

    boolean isScheAdd = false;

    final static int DIALOG_ID = 1;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        setContentView(R.layout.activity_budget_info);
        super.onCreate(savedInstanceState);
        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar); //액션바 설정
        setSupportActionBar(toolbar);

        ActionBar actionBar = getSupportActionBar(); //액션바 색깔
        actionBar.setBackgroundDrawable(new ColorDrawable(0xFF9CCC65));

        FloatingActionButton fab = (FloatingActionButton) findViewById(R.id.fab);
        fab.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                showDialog(DIALOG_ID);
            }
        });
        // SQLiteOpenHelper 클래스의 subclass인 DBHelper 클래스 객체 생성
        DBHelper = new DBHelper(this);
        // DBHelper 객체를 이용하여 DB 생성
        try {
            bdgt_db = DBHelper.getWritableDatabase();
        } catch (SQLiteException e) {
            bdgt_db = DBHelper.getReadableDatabase();
        }

        Intent intent = getIntent();
        if(intent != null) {
            budgetID = intent.getIntExtra("BDGTID", 0);
            isScheAdd = intent.getBooleanExtra("ISSCHEADD", false);
        }
        tv = (TextView)findViewById(R.id.totalB);
        calTotalCost();
        tv.setText(Integer.toString(total_cost));

        // budget 테이블에서 모든 레코드를 retrieve
        onSettings();
    }

    public void onSettings(){
        c = bdgt_db.rawQuery("SELECT * FROM budget WHERE bdgtid='" +budgetID+ "';", null);
        String[] from = {"item", "cost"};
        int[] to = {android.R.id.text1, android.R.id.text2};
        // SimpleCursorAdapter 객체 생성
        // 하나의 리스트 아이템에 2개의 텍스트뷰를 표시하는 레이아웃
        adapter = new SimpleCursorAdapter(this,
                android.R.layout.simple_list_item_2, c, from, to);

        list = (ListView)findViewById(R.id.binfoList);
        // 리스트뷰 객체에 어댑터 설정
        list.setAdapter(adapter);

        registerForContextMenu(list);

        adapter.notifyDataSetChanged();
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();

        DBHelper.close();
        c.close();
    }

    // EditText가 비어있는지 판별
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
        final View layout = inflater.inflate(R.layout.budgetinfodialog,(ViewGroup) findViewById(R.id.bilist));
        switch (id) {
            case DIALOG_ID:
                AlertDialog.Builder builder = new AlertDialog.Builder(this);
                builder.setIcon(R.drawable.ic_info_black_24dp);
                builder.setTitle("항목과 비용을 입력하세요.");
                builder.setView(layout);

                final EditText etitem = (EditText) layout.findViewById(R.id.etitem);
                final EditText etcost = (EditText) layout.findViewById(R.id.etcost);

                builder.setPositiveButton("Yes", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        if(isEmpty(etitem)) {
                            Toast.makeText(getApplicationContext(), "이름을 입력하세요.", Toast.LENGTH_SHORT).show();
                            return;
                        }
                        if(isEmpty(etcost)) {
                            Toast.makeText(getApplicationContext(), "비용을 입력하세요.", Toast.LENGTH_SHORT).show();
                            return;
                        }

                        String item = etitem.getText().toString();
                        if(isSame(item)) {
                            Toast.makeText(getApplicationContext(), "같은 이름이 있습니다!", Toast.LENGTH_SHORT).show();
                            return;
                        }

                        int cost = Integer.parseInt(etcost.getText().toString());

                        bdgt_db.execSQL("INSERT INTO budget VALUES (null, '" + budgetID + "', '" + item + "', '" + cost + "');");

                        calTotalCost();

                        onSettings();

                        Toast.makeText(getApplicationContext(), "성공적으로 추가되었음", Toast.LENGTH_SHORT).show();
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
            c = bdgt_db.rawQuery("SELECT * FROM budget WHERE item='"+ s + "';", null);

            if(c.getCount() == 0)
                return false;
            else
                return true;
        }catch (NullPointerException e){
            return true;
        }
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
                if(isScheAdd) {
                    Intent intent = new Intent();

                    intent.putExtra("ISSELECT", true);
                    intent.putExtra("TOTALCOST", total_cost);
                    Log.i("tcadd----BI_itemSel", Integer.toString(total_cost));

                    setResult(RESULT_OK, intent);
                    finish();
                }
                else
                    Toast.makeText(getApplicationContext(), "일정 관리에서 등록하세요.", Toast.LENGTH_SHORT).show();
                return true;
            default:
                return super.onOptionsItemSelected(item);
        }
    }

    public void calTotalCost() {
        total_cost = 0;
        try {
            c = bdgt_db.rawQuery("SELECT cost FROM budget WHERE bdgtid='" + budgetID + "';", null);
            if (c.getCount() == 0) {
                Log.i("totalcost----->","return");
                return;
            }
            c.moveToFirst();

            for(int i = 0; i < c.getCount(); i++) {
                total_cost += c.getInt(0);
                c.moveToNext();
            }

            tv.setText(Integer.toString(total_cost));
            bdgt_db.execSQL("UPDATE tbudget SET tcost='" + total_cost + "'WHERE bdgtid='" + budgetID + "';");
        }catch (NullPointerException e){
            total_cost = 0;
            Log.i("totalcost----totalcost>","null");
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
                // 삭제할 아이템이 없으면 메시지 출력 후 종료
                if (count == 0) {
                    Toast.makeText(getApplicationContext(), "삭제할 아이템이 없습니다", Toast.LENGTH_SHORT).show();
                    return false;
                }
                c = (Cursor)list.getAdapter().getItem(m_pos);
                String tmp = (c.getString(c.getColumnIndex("item")));

                c = bdgt_db.rawQuery("SELECT * FROM budget WHERE item='" + tmp + "';", null);
                c.moveToFirst();
                int tmpnum = c.getInt(1);

                bdgt_db.execSQL("DELETE FROM budget WHERE bdgtid='"+ tmpnum + "' AND item='" + tmp + "';");

                onSettings();
                adapter.notifyDataSetChanged(); // 리스트뷰 갱신

                return true;
            default:
                return super.onContextItemSelected(item);
        }
    }
}