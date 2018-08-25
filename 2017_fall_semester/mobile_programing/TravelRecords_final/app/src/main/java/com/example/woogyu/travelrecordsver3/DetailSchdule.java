package com.example.woogyu.travelrecordsver3;

import android.app.DatePickerDialog;
import android.app.Dialog;
import android.app.DialogFragment;
import android.app.TimePickerDialog;
import android.content.Intent;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteException;
import android.graphics.drawable.ColorDrawable;
import android.os.Bundle;
import android.support.v7.app.ActionBar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.text.TextUtils;
import android.view.View;
import android.widget.DatePicker;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.TimePicker;
import android.widget.Toast;

import java.util.Calendar;

/**
 * Created by WooJin on 2017-12-20.
 */
public class DetailSchdule extends AppCompatActivity{

    private DBHelper ds_Helper;
    private SQLiteDatabase ds_db;
    private Cursor c;

    int itemID = 0;
    String m_date;
    String m_time;
    String m_dest;
    String m_room;
    String m_memo;
    int isSucc;
    boolean isEdit = false;

    TextView dsDate;
    TextView dsTime;
    EditText dsDest;
    EditText dsRoom;
    EditText dsMemo;


    public static class DatePickerFragment extends DialogFragment implements DatePickerDialog.OnDateSetListener{

        TextView mT;

        public void setEditText(TextView et) {
            mT = et;
        }

        @Override
        public Dialog onCreateDialog(Bundle savedInstanceState) {
            Calendar cal = Calendar.getInstance();

            // DatePickerDialog 클래스의 생성자
            // DatePickerDialog(Context context, DatePickerDialog.OnDateSetListener listener, int year, int month, int dayOfMonth)
            // Creates a new date picker dialog for the specified date using the parent context's default date picker dialog theme.

            return new DatePickerDialog(getActivity(), this, cal.get(Calendar.YEAR), cal.get(Calendar.MONTH), cal.get(Calendar.DATE));
        }

        @Override
        public void onDateSet(DatePicker view, int year, int monthOfYear, int dayOfMonth) {
            mT.setText(year + "/" + (monthOfYear + 1) + "/" + dayOfMonth);
        }
    }

    public static class TimePickerFragment extends DialogFragment implements TimePickerDialog.OnTimeSetListener {

        TextView mT;

        public void setEditText(TextView et) {
            mT = et;
        }

        @Override
        public Dialog onCreateDialog(Bundle savedInstanceState) {
            Calendar cal = Calendar.getInstance();

            // TimePickerDialog 클래스의 생성자
            // TimePickerDialog(Context context, TimePickerDialog.OnTimeSetListener listener, int hourOfDay, int minute, boolean is24HourView)
            // Creates a new time picker dialog.

            return new TimePickerDialog(getActivity(), this, cal.get(Calendar.HOUR_OF_DAY), cal.get(Calendar.MINUTE), true);
        }

        @Override
        public void onTimeSet(TimePicker view, int hourOfDay, int min) {
            mT.setText(hourOfDay + ":" + min);
        }
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_detail_schdule);

        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar); //액션바 설정
        setSupportActionBar(toolbar);

        ActionBar actionBar = getSupportActionBar(); //액션바 색깔
        actionBar.setBackgroundDrawable(new ColorDrawable(0xFF1DE9B6));

        dsDate = (TextView)findViewById(R.id.dateText);
        dsTime = (TextView)findViewById(R.id.timeText);
        dsDest = (EditText)findViewById(R.id.dest);
        dsRoom = (EditText)findViewById(R.id.rooms);
        dsMemo = (EditText)findViewById(R.id.memo);

        Intent in = getIntent();
        if(in != null) {
            itemID = in.getIntExtra("SID", 0);
            m_date = in.getStringExtra("DATE");
            m_time = in.getStringExtra("TIME");
            m_dest = in.getStringExtra("NAME");
            m_room = in.getStringExtra("ROOM");
            m_memo = in.getStringExtra("MEMO");
            isSucc = Integer.parseInt(in.getStringExtra("SUCC"));
            isEdit = in.getBooleanExtra("ISEDIT", false);
        }

        if(isEdit) {
            dsDate.setText(m_date);
            dsTime.setText(m_time);
            dsDest.setText(m_dest);
            dsRoom.setText(m_room);
            dsMemo.setText(m_memo);
        }

        // SQLiteOpenHelper 클래스의 subclass인 DBHelper 클래스 객체 생성
        ds_Helper = new DBHelper(this);
        // DBHelper 객체를 이용하여 DB 생성
        try {
            ds_db = ds_Helper.getWritableDatabase();
        } catch (SQLiteException e) {
            ds_db = ds_Helper.getReadableDatabase();
        }

        // detailSchedule 테이블에서 모든 레코드를 retrieve
        c = ds_db.rawQuery("SELECT * FROM detailSchedule", null);

        // OnClickListener를 설정(무명클래스로 이벤트 리스너 객체를 생성하는 방식)하고 onClick 메소드 구현
        dsDate.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                TextView editText = (TextView) findViewById(R.id.dateText);

                DetailSchdule.DatePickerFragment dpf = new DetailSchdule.DatePickerFragment();
                dpf.setEditText(editText);
                dpf.show(getFragmentManager(), "datePicker");
            }
        });

        dsTime.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                TextView editText = (TextView) findViewById(R.id.timeText);

                DetailSchdule.TimePickerFragment tpf = new DetailSchdule.TimePickerFragment();
                tpf.setEditText(editText);
                tpf.show(getFragmentManager(), "timePicker");
            }
        });
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();

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

    public boolean isSame(String s) {
        try {
            c = ds_db.rawQuery("SELECT * FROM detailSchedule WHERE dest='"+ s + "';", null);
            if(c.getCount() == 0)
                return false;
            else
                return true;
        }catch (NullPointerException e){
            return true;
        }
    }

    // 추가 버튼을 눌렀을 때 호출되는 메소드
    public void save(View v) {
        if(isEmpty(dsDest)) {
            Toast.makeText(getApplicationContext(), "목적지를 등록하세요!", Toast.LENGTH_SHORT).show();
            return;
        }
        if(isEmpty(dsRoom))
            dsRoom.setText("숙소 없음");
        if(isEmpty(dsMemo))
            dsMemo.setText("메모 없음");
        if(dsDate.getText() == "") { dsDate.setText("0000/00/00"); }
        if(dsTime.getText() == "") { dsTime.setText("00 : 00"); }

        String date = dsDate.getText().toString();
        String time = dsTime.getText().toString();
        String dest = dsDest.getText().toString();
        String room = dsRoom.getText().toString();
        String memo = dsMemo.getText().toString();

        if(isSame(dest)) {
            Toast.makeText(getApplicationContext(), "같은 목적지가 있습니다!", Toast.LENGTH_SHORT).show();
            return;
        }

        if(!isEdit) {
            ds_db.execSQL("INSERT INTO detailSchedule VALUES (null, '"
                    + itemID + "', '" + date + "', '" + time + "', '" + dest + "', '" + room + "', '" + memo + "', 0);");
            Toast.makeText(getApplicationContext(), "성공적으로 추가되었음", Toast.LENGTH_SHORT).show();

        }
        else {
            Toast.makeText(getApplicationContext(), "성공적으로 수정되었음", Toast.LENGTH_SHORT).show();
        }

        // EditText 초기화
        dsDate.setText("");
        dsTime.setText("");
        dsDest.setText("");
        dsRoom.setText("");
        dsMemo.setText("");
        finish();
    }

    public void cancle(View v) {
        finish();
    }
}