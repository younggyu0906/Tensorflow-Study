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
import android.widget.BaseAdapter;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;

import java.util.ArrayList;

/**
 * Created by WooJin on 2017-12-20.
 */
public class ScheduleProgress extends AppCompatActivity{

    private ActionMode mActionMode;             // 액션모드 객체 선언
    private DBHelper ds_Helper;
    private SQLiteDatabase ds_db;
    Cursor cursor;
    int itemID = 0;
    int m_pos = 0;
    final static int DIALOG2_ID = 2;

    TextView Tv1;
    TextView Tv2;
    TextView Tv3;
    TextView Tv4;
    TextView Tv5;
    TextView Tv6;

    TravelAdapter adapter;
    ListView lv;

    ArrayList<TvProgress> m_al = new ArrayList<TvProgress>();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_schedule_progress);

        Tv1 = (TextView) findViewById(R.id.tgtext1);
        Tv2 = (TextView) findViewById(R.id.tgtext2);
        Tv3 = (TextView) findViewById(R.id.tgtext3);
        Tv4 = (TextView) findViewById(R.id.tgtext4);
        Tv5 = (TextView) findViewById(R.id.tgtext_count);
        Tv6 = (TextView) findViewById(R.id.tgtext_edate);

        // adapter
        adapter = new TravelAdapter(getApplicationContext(), R.layout.viewitem, m_al);
        lv = (ListView) findViewById(R.id.progressList);
        lv.setAdapter(adapter);
        registerForContextMenu(lv);

        Intent in = getIntent();
        if (in != null) {
            itemID = in.getIntExtra("SID", 0);
            Tv1.setText(in.getStringExtra("NAME"));
            Tv2.setText(in.getStringExtra("SDATE"));
            Tv3.setText(in.getStringExtra("BDGT") + "원");
            Tv4.setText(in.getStringExtra("MTRL"));
            Tv5.setText(in.getStringExtra("NOP") + "명");
            Tv6.setText(in.getStringExtra("EDATE"));
        }

        Log.i("scheID-----sp", Integer.toString(itemID));

        // SQLiteOpenHelper 클래스의 subclass인 DBHelper 클래스 객체 생성
        ds_Helper = new DBHelper(this);
        // DBHelper 객체를 이용하여 DB 생성
        try {
            ds_db = ds_Helper.getWritableDatabase();
        } catch (SQLiteException e) {
            ds_db = ds_Helper.getReadableDatabase();
        }
        cursor = ds_db.rawQuery("SELECT * FROM detailSchedule WHERE schid='" + itemID + "';", null);
        while (cursor.moveToNext()) {
            m_al.add(new TvProgress(R.drawable.prog1_true,
                    cursor.getString(4),
                    cursor.getString(2) + " " + cursor.getString(3),
                    Boolean.valueOf(cursor.getString(5))));
        }
        adapter.setn(n);
        // 이벤트 처리
        lv.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                m_pos = position;
                showDialog(DIALOG2_ID);
            }
        });

        FloatingActionButton fab = (FloatingActionButton) findViewById(R.id.spfab);
        fab.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent intent = new Intent(ScheduleProgress.this, DetailSchdule.class);
                intent.putExtra("SID", itemID);
                intent.putExtra("SUCC", "0");
                startActivity(intent);
            }
        });
    }

    int n;
    @Override
    protected void onStart() {
        super.onStart();
        m_al.clear();
        cursor = ds_db.rawQuery("SELECT * FROM detailSchedule WHERE schid='" + itemID + "';", null);
        while(cursor.moveToNext()) {
            m_al.add(new TvProgress(R.drawable.prog1_true,
                    cursor.getString(4),
                    cursor.getString(2) + " " + cursor.getString(3),
                    Boolean.valueOf(cursor.getString(5))));
        }
        adapter.notifyDataSetChanged();
    }

    @Override
    protected Dialog onCreateDialog(int id) {
        Context mContext = getApplicationContext();
        LayoutInflater inflater = (LayoutInflater) mContext.getSystemService(LAYOUT_INFLATER_SERVICE);
        final View layout = inflater.inflate(R.layout.detail_info,(ViewGroup) findViewById(R.id.dinfo));
        switch (id) {
            case DIALOG2_ID:
                AlertDialog.Builder builder = new AlertDialog.Builder(this);
                builder.setTitle("세부 일정");
                builder.setView(layout);

                String sd = m_al.get(m_pos).pName;
                cursor = ds_db.rawQuery("SELECT * FROM detailSchedule WHERE schid='"+ itemID +
                        "' AND dest='" + sd + "';", null);

                TextView et1 = (TextView) layout.findViewById(R.id.d_date);
                TextView et2 = (TextView) layout.findViewById(R.id.d_time);
                TextView et3 = (TextView) layout.findViewById(R.id.d_dest);
                TextView et4 = (TextView) layout.findViewById(R.id.d_room);
                TextView et5 = (TextView) layout.findViewById(R.id.d_memo);

                cursor.moveToFirst();
                et1.setText(cursor.getString(2));
                et2.setText(cursor.getString(3));
                et3.setText(cursor.getString(4));
                et4.setText(cursor.getString(5));
                et5.setText(cursor.getString(6));

                builder.setNegativeButton("닫기", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        dialog.dismiss();
                    }
                });
                AlertDialog alert = builder.create();
                alert.show();
                return alert;
        }
        return null;
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
        String sd = m_al.get(m_pos).pName;


        switch (item.getItemId()){
            case 1:
                m_al.remove(m_pos);

                ds_db.execSQL("DELETE FROM detailSchedule WHERE schid='"+ itemID +
                        "' AND dest='" + sd + "';");
                // 삭제

                adapter.notifyDataSetChanged(); // 리스트뷰 갱신
                return true;
            case 2:

                return true;
            default:
                return super.onContextItemSelected(item);

        }
    }


}

class TravelAdapter extends BaseAdapter {
    Context context;            // 현재 화면의 제어권자
    int layout;                 // 한행을 그려줄 layout
    ArrayList<TvProgress> al;    // 다량의 데이터
    LayoutInflater inf; // 화면을 그려줄 때 필요
    int n;

    public void setn( int n){
        this.n = n;
    }

    public TravelAdapter(Context context, int layout, ArrayList<TvProgress> al) {
        this.context = context;
        this.layout = layout;
        this.al = al;
        this.inf = (LayoutInflater)context.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
    }
    @Override
    public int getCount() { // 총 데이터의 개수를 리턴
        return al.size();
    }
    @Override
    public Object getItem(int position) { // 해당번째의 데이터 값
        return al.get(position);
    }
    @Override
    public long getItemId(int position) { // 해당번째의 고유한 id 값
        return position;
    }
    @Override // 해당번째의 행에 내용을 셋팅(데이터와 레이아웃의 연결관계 정의)
    public View getView(int position, View convertView, ViewGroup parent) {
        if (convertView == null)
            convertView = inf.inflate(layout, null);

        ImageView tvIv = (ImageView)convertView.findViewById(R.id.itemicon);
        TextView tvName=(TextView)convertView.findViewById(R.id.dtlschname);
        TextView tvdt =(TextView)convertView.findViewById(R.id.progress);

        TvProgress m = al.get(position);

        tvIv.setImageResource(R.drawable.prog1_true);
        tvIv.setImageAlpha(m.pIcon);
        tvName.setText(m.pName);
        tvdt.setText(m.pDT);
        //tvprog.setText(m.isProgress ? "성공" : "실패");
        return convertView;
    }
}

class TvProgress { // 자바 빈 (java Bean)
    int pIcon; // 사진 - res/drawable
    String pName = "";
    String pDT = "";
    boolean isProgress;

    // 생성자가 있으면 객체 생성시 편리하다
    public TvProgress(int img, String name, String dt, boolean isprog) {
        this.pIcon = img;
        this.pName = name;
        this.pDT = dt;
        this.isProgress = isprog;
    }
    public TvProgress() {}// 기존 코드와 호환을 위해서 생성자 작업시 기본생성자도 추가






}