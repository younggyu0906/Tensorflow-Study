package com.example.woogyu.travelrecordsver3;

import android.app.DatePickerDialog;
import android.app.Dialog;
import android.app.DialogFragment;
import android.content.Intent;
import android.database.Cursor;
import android.graphics.drawable.ColorDrawable;
import android.os.Bundle;
import android.support.v7.app.ActionBar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.text.TextUtils;
import android.util.Log;
import android.view.ContextMenu;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.AdapterView;
import android.widget.DatePicker;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Calendar;

public class ScheduleAdd extends AppCompatActivity {

    static final int GET_STRING = 10;

    int m_pos = 0;
    int sId = 0;
    boolean isNew = false;

    EditText tName;
    TextView tSDate;
    TextView tEDate;
    TextView tBdgt;
    EditText tMtrl;
    EditText tNOP;

    // file name
    private final String tvName = "name.txt";
    private final String tvSDate = "sdate.txt";
    private final String tvEDate = "edate.txt";
    private final String tvBudget = "budget.txt";
    private final String tvMtrl = "material.txt";
    private final String tvNOP = "people.txt";
    private final String tvsId = "sId.txt";

    // ArrayList
    private ArrayList<String> nameItem = new ArrayList<String>();
    private ArrayList<String> sdateItem = new ArrayList<String>();
    private ArrayList<String> edateItem = new ArrayList<String>();
    private ArrayList<String> bdgtItem = new ArrayList<String>();
    private ArrayList<String> mtrlItem = new ArrayList<String>();
    private ArrayList<String> nopItem = new ArrayList<String>();
    private ArrayList<String> sIdItem = new ArrayList<String>();

    public static class DatePickerFragment extends DialogFragment implements DatePickerDialog.OnDateSetListener {

        TextView m_DateText;

        public void setEditText(TextView eText) {
            m_DateText = eText;
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
            m_DateText.setText(year + "/" + (monthOfYear + 1) + "/" + dayOfMonth);
        }
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_schedule_add);

        Toolbar toolBar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolBar);
        ActionBar actionBar = getSupportActionBar();
        actionBar.setBackgroundDrawable(new ColorDrawable(0xFF1DE9B6));

        tName = (EditText) findViewById(R.id.travel_name);
        tSDate = (TextView)findViewById(R.id.sDateText);
        tEDate = (TextView)findViewById(R.id.eDateText);
        tBdgt = (TextView)findViewById(R.id.budget);
        tMtrl = (EditText)findViewById(R.id.materials);
        tNOP = (EditText)findViewById(R.id.NumOfPeople);

        Intent intent = getIntent();
        if(intent != null) {
            m_pos = intent.getIntExtra("POSITION", 0);
            isNew = intent.getBooleanExtra("ISNEW", true);
        }

        loadItemsFromFile();                // 파일에서 불러옴

        if(!isNew) {
            tName.setText(nameItem.get(m_pos).toString());
            tSDate.setText(sdateItem.get(m_pos).toString());
            tEDate.setText(edateItem.get(m_pos).toString());
            tBdgt.setText(bdgtItem.get(m_pos).toString());
            tMtrl.setText(mtrlItem.get(m_pos).toString());
            tNOP.setText(nopItem.get(m_pos).toString());
        }

        if(!sIdItem.isEmpty())
            sId = (Integer.parseInt(sIdItem.get(sIdItem.size() - 1))) + 1;
        Log.i("scheID-----add onCreate", Integer.toString(sId));

        // OnClickListener를 설정(무명클래스로 이벤트 리스너 객체를 생성하는 방식)하고 onClick 메소드 구현
        tSDate.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                TextView editText = (TextView) findViewById(R.id.sDateText);
                DatePickerFragment dpf = new DatePickerFragment();
                dpf.setEditText(editText);
                dpf.show(getFragmentManager(), "datePicker1");
            }
        });

        tEDate.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                TextView editText = (TextView) findViewById(R.id.eDateText);

                DatePickerFragment dpf = new DatePickerFragment();
                dpf.setEditText(editText);
                dpf.show(getFragmentManager(), "datePicker2");
            }
        });
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

    public void onClick(View view) {

        switch (view.getId()) {
            case R.id.add :
                Toast.makeText(getApplicationContext(), "예산 등록", Toast.LENGTH_SHORT).show();
                Intent in = new Intent(ScheduleAdd.this, Budget.class);
                in.putExtra("ISSCHEADD", true);
                Log.i("tcadd----SA_onSAFR", "엑티비티시작");
                startActivityForResult(in, GET_STRING);
                break;
        }
    }

    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        if(requestCode == GET_STRING) {
            Log.i("tcadd----SA_oAR", "requestCode");
            if(resultCode == RESULT_OK) {
                int tmp = data.getIntExtra("TOTALCOST", 0);
                tBdgt.setText(Integer.toString(tmp));
                Log.i("tcadd----SA_oAR", Integer.toString(tmp));
            }
        }
    }

    // 리스트 뷰 아이템을 파일에 저장
    private void saveItemsToFile() {
        // 파일 객체 선언
        File file1 = new File(getFilesDir(), tvName);
        File file2 = new File(getFilesDir(), tvSDate);
        File file3 = new File(getFilesDir(), tvEDate);
        File file4 = new File(getFilesDir(), tvBudget);
        File file5 = new File(getFilesDir(), tvMtrl);
        File file6 = new File(getFilesDir(), tvNOP);
        File file7 = new File(getFilesDir(), tvsId);

        // 한 줄 단위로 처리하기 위한 FileWriter 객체 선언
        // FileInputStream은 byte와 char(또는 String)간의 형 변환을 해야함, 버퍼 인덱스의 경계에 따라 타입 변환으로 잘못된 데이터를 가져올 수 있음
        FileWriter fw1 = null;
        FileWriter fw2 = null;
        FileWriter fw3 = null;
        FileWriter fw4 = null;
        FileWriter fw5 = null;
        FileWriter fw6 = null;
        FileWriter fw7 = null;

        // 파일 입출력의 성능을 향상시키기 위한 방법으로 버퍼를 사용한 입출력
        // BufferedWriter 객체 선언
        BufferedWriter bufwr1 = null;
        BufferedWriter bufwr2 = null;
        BufferedWriter bufwr3 = null;
        BufferedWriter bufwr4 = null;
        BufferedWriter bufwr5 = null;
        BufferedWriter bufwr6 = null;
        BufferedWriter bufwr7 = null;

        try {
            // 파일 열기
            fw1 = new FileWriter(file1);
            fw2 = new FileWriter(file2);
            fw3 = new FileWriter(file3);
            fw4 = new FileWriter(file4);
            fw5 = new FileWriter(file5);
            fw6 = new FileWriter(file6);
            fw7 = new FileWriter(file7);

            bufwr1 = new BufferedWriter(fw1);
            bufwr2 = new BufferedWriter(fw2);
            bufwr3 = new BufferedWriter(fw3);
            bufwr4 = new BufferedWriter(fw4);
            bufwr5 = new BufferedWriter(fw5);
            bufwr6 = new BufferedWriter(fw6);
            bufwr7 = new BufferedWriter(fw7);

            for (String str : nameItem) {   // 버퍼에 nameItem 쓰기
                bufwr1.write(str);              // 문자열 저장
                bufwr1.newLine();               // 줄 바꿈
            }

            for (String str2 : sdateItem) {   // 버퍼에 sdateItem 쓰기
                bufwr2.write(str2) ;              // 문자열 저장
                bufwr2.newLine() ;               // 줄 바꿈
            }

            for (String str3 : edateItem) {   // 버퍼에 urlItem 쓰기
                bufwr3.write(str3) ;              // 문자열 저장
                bufwr3.newLine() ;               // 줄 바꿈
            }

            for (String str4 : bdgtItem) {   // 버퍼에 urlItem 쓰기
                bufwr4.write(str4) ;              // 문자열 저장
                bufwr4.newLine() ;               // 줄 바꿈
            }

            for (String str5 : mtrlItem) {   // 버퍼에 urlItem 쓰기
                bufwr5.write(str5) ;              // 문자열 저장
                bufwr5.newLine() ;               // 줄 바꿈
            }

            for (String str6 : nopItem) {   // 버퍼에 urlItem 쓰기
                bufwr6.write(str6) ;              // 문자열 저장
                bufwr6.newLine() ;               // 줄 바꿈
            }

            for (String str7 : sIdItem) {   // 버퍼에 urlItem 쓰기
                bufwr7.write(str7) ;              // 문자열 저장
                bufwr7.newLine() ;               // 줄 바꿈
            }

            // write data to the file.
            bufwr1.flush();
            bufwr2.flush();
            bufwr3.flush();
            bufwr4.flush();
            bufwr5.flush();
            bufwr6.flush();
            bufwr7.flush();

        } catch (Exception e) {
            e.printStackTrace() ;
        }

        try {
            // 파일 닫기
            if (bufwr1 != null) { bufwr1.close(); }
            if (bufwr2 != null) { bufwr2.close(); }
            if (bufwr3 != null) { bufwr3.close(); }
            if (bufwr4 != null) { bufwr4.close(); }
            if (bufwr5 != null) { bufwr5.close(); }
            if (bufwr6 != null) { bufwr6.close(); }
            if (bufwr7 != null) { bufwr7.close(); }

            if (fw1 != null) { fw1.close(); }
            if (fw2 != null) { fw2.close(); }
            if (fw3 != null) { fw3.close(); }
            if (fw4 != null) { fw4.close(); }
            if (fw5 != null) { fw5.close(); }
            if (fw6 != null) { fw6.close(); }
            if (fw7 != null) { fw7.close(); }

        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    // 리스트뷰 아이템을 파일로부터 읽기
    private void loadItemsFromFile() {
        // 파일 객체 선언
        File file1 = new File(getFilesDir(), tvName);
        File file2 = new File(getFilesDir(), tvSDate);
        File file3 = new File(getFilesDir(), tvEDate);
        File file4 = new File(getFilesDir(), tvBudget);
        File file5 = new File(getFilesDir(), tvMtrl);
        File file6 = new File(getFilesDir(), tvNOP);
        File file7 = new File(getFilesDir(), tvsId);

        // 파일리더 객체 선언
        FileReader fr1 = null;
        FileReader fr2 = null;
        FileReader fr3 = null;
        FileReader fr4 = null;
        FileReader fr5 = null;
        FileReader fr6 = null;
        FileReader fr7 = null;

        // 버퍼리더 객체 선언
        BufferedReader bufrd1 = null;
        BufferedReader bufrd2 = null;
        BufferedReader bufrd3 = null;
        BufferedReader bufrd4 = null;
        BufferedReader bufrd5 = null;
        BufferedReader bufrd6 = null;
        BufferedReader bufrd7 = null;

        // 파일로 부터 한 라인을 읽기 위한 String 객체 선언
        String str1;
        String str2;
        String str3;
        String str4;
        String str5;
        String str6;
        String str7;

        if (file1.exists()) {
            try {
                // 파일 열기
                fr1 = new FileReader(file1);
                fr2 = new FileReader(file2);
                fr3 = new FileReader(file3);
                fr4 = new FileReader(file4);
                fr5 = new FileReader(file5);
                fr6 = new FileReader(file6);
                fr7 = new FileReader(file7);

                bufrd1 = new BufferedReader(fr1);
                bufrd2 = new BufferedReader(fr2);
                bufrd3 = new BufferedReader(fr3);
                bufrd4 = new BufferedReader(fr4);
                bufrd5 = new BufferedReader(fr5);
                bufrd6 = new BufferedReader(fr6);
                bufrd7 = new BufferedReader(fr7);

                // 파일로부터 한 라인 읽기
                while ((str1 = bufrd1.readLine()) != null) { nameItem.add(str1); }
                while ((str2 = bufrd2.readLine()) != null) { sdateItem.add(str2); }
                while ((str3 = bufrd3.readLine()) != null) { edateItem.add(str3); }
                while ((str4 = bufrd4.readLine()) != null) { bdgtItem.add(str4); }
                while ((str5 = bufrd5.readLine()) != null) { mtrlItem.add(str5); }
                while ((str6 = bufrd6.readLine()) != null) { nopItem.add(str6); }
                while ((str7 = bufrd7.readLine()) != null) { sIdItem.add(str7); }

                // 버퍼리더와 파일리더 닫기
                bufrd1.close();
                bufrd2.close();
                bufrd3.close();
                bufrd4.close();
                bufrd5.close();
                bufrd6.close();
                bufrd7.close();

                fr1.close();
                fr2.close();
                fr3.close();
                fr4.close();
                fr5.close();
                fr6.close();
                fr7.close();

            } catch (Exception e) {
                e.printStackTrace() ;
            }
        }
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.menu_schedule_add, menu);
        Log.i("asd","asd");
        return true;
    }
    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        int id = item.getItemId();

        if (id == R.id.action_schedule_add_exit) {
            finish();
            return true;
        }
        else if(id == R.id.action_schedule_add_save){
            if(isEmpty(tName)) {
                Toast.makeText(getApplicationContext(), "이름을 등록하세요!", Toast.LENGTH_SHORT).show();
                return true;
            }
            if(tSDate.getText() == "") { tSDate.setText("0000/00/00"); }
            if(tEDate.getText() == "") { tEDate.setText("9999/99/99"); }
            if(tBdgt.getText() == "") { tBdgt.setText("0"); }
            if(isEmpty(tMtrl)) { tMtrl.setText("없음"); }
            if(isEmpty(tNOP)) { tNOP.setText("1"); }

            if(isNew) {     // 새로 추가
                nameItem.add(tName.getText().toString());
                sdateItem.add(tSDate.getText().toString());
                edateItem.add(tEDate.getText().toString());
                bdgtItem.add(tBdgt.getText().toString());
                mtrlItem.add(tMtrl.getText().toString());
                nopItem.add(tNOP.getText().toString());
                sIdItem.add(Integer.toString(sId));
                Log.i("scheID-----save", Integer.toString(sId));
                for(int i = 0; i < sIdItem.size(); i++)
                    Log.i("scheID-----saforloop", sIdItem.get(i).toString());
            }
            else {          // 항목 수정
                nameItem.set(m_pos, tName.getText().toString());
                sdateItem.set(m_pos, tSDate.getText().toString());
                edateItem.set(m_pos, tEDate.getText().toString());
                bdgtItem.set(m_pos, tBdgt.getText().toString());
                mtrlItem.set(m_pos, tMtrl.getText().toString());
                nopItem.set(m_pos, tNOP.getText().toString());
            }
            saveItemsToFile();
            finish();
            return true;
        }
        return super.onOptionsItemSelected(item);
    }
}