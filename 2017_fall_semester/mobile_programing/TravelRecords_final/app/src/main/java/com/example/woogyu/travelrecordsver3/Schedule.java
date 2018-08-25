package com.example.woogyu.travelrecordsver3;

import android.content.Intent;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteException;
import android.graphics.drawable.ColorDrawable;
import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.v7.app.ActionBar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.util.Log;
import android.view.ActionMode;
import android.view.ContextMenu;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.Toast;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;

/**
 * Created by WooJin on 2017-12-20.
 */
public class Schedule extends AppCompatActivity implements AdapterView.OnItemClickListener{

    private DBHelper ds_Helper;
    private SQLiteDatabase ds_db;

    private ActionMode mActionMode;             // 액션모드 객체 선언
    int m_pos = 0;

    private ListView m_ListView;                // listview 선언
    private ArrayAdapter<String> m_Adapter;     // adpater

    // ArrayList
    private ArrayList<String> nameItem = new ArrayList<String>();
    private ArrayList<String> sdateItem = new ArrayList<String>();
    private ArrayList<String> edateItem = new ArrayList<String>();
    private ArrayList<String> bdgtItem = new ArrayList<String>();
    private ArrayList<String> mtrlItem = new ArrayList<String>();
    private ArrayList<String> nopItem = new ArrayList<String>();
    private ArrayList<String> sIdItem = new ArrayList<String>();

    // file name
    private final String tvName = "name.txt";
    private final String tvSDate = "sdate.txt";
    private final String tvEDate = "edate.txt";
    private final String tvBudget = "budget.txt";
    private final String tvMtrl = "material.txt";
    private final String tvNOP = "people.txt";
    private final String tvsId = "sId.txt";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_schedule);
        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar); //액션바 설정
        setSupportActionBar(toolbar);

        ActionBar actionBar = getSupportActionBar(); //액션바 색깔
        actionBar.setBackgroundDrawable(new ColorDrawable(0xFF1DE9B6));

        // Android에서 제공하는 String 문자열 하나를 출력하는 layout으로 어댑터 생성
        m_Adapter = new ArrayAdapter<String>(this, android.R.layout.simple_list_item_1, nameItem);
        // Xml에서 추가한 ListView의 객체
        m_ListView = (ListView) findViewById(R.id.list);
        // ListView에 어댑터 연결
        m_ListView.setAdapter(m_Adapter);
        // ListView 아이템 터치 시 이벤트를 처리할 리스너 설정
        m_ListView.setOnItemClickListener(this);
        // ListView 아이템 롱클릭 시 이벤트를 처리할 리스너 설정
        registerForContextMenu(m_ListView);

        loadItemsFromFile();                // 파일에서 불러옴
        m_Adapter.notifyDataSetChanged();   // 리스트뷰 갱신

        // SQLiteOpenHelper 클래스의 subclass인 DBHelper 클래스 객체 생성
        ds_Helper = new DBHelper(this);
        // DBHelper 객체를 이용하여 DB 생성
        try {
            ds_db = ds_Helper.getWritableDatabase();
        } catch (SQLiteException e) {
            ds_db = ds_Helper.getReadableDatabase();
        }
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.menu_schedule, menu);
        return true;
    }
    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        int id = item.getItemId();
        if (id == R.id.action_schedule_exit) {
            finish();
            return true;
        }
        else if(id == R.id.action_schedule_save){
            Intent intent = new Intent(Schedule.this, ScheduleAdd.class);
            Toast.makeText(getApplicationContext(), "일정 등록", Toast.LENGTH_SHORT).show();
            startActivity(intent);
            return true;
        }
        return super.onOptionsItemSelected(item);
    }

    @Override
    protected void onStart() {
        super.onStart();
        loadItemsFromFile();                // 파일에서 불러옴
        m_Adapter.notifyDataSetChanged();   // 리스트뷰 갱신
    }

    @Override
    public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
        Intent intent = new Intent(this, ScheduleProgress.class);
        intent.putExtra("POSITION", position);
        intent.putExtra("NAME", nameItem.get(position).toString());
        intent.putExtra("SDATE", sdateItem.get(position).toString());
        intent.putExtra("EDATE", edateItem.get(position).toString());
        intent.putExtra("BDGT", bdgtItem.get(position).toString());
        intent.putExtra("MTRL", mtrlItem.get(position).toString());
        intent.putExtra("NOP", nopItem.get(position).toString());
        intent.putExtra("SID", Integer.parseInt(sIdItem.get(position).toString()));
        Log.i("scheID-----schedule", sIdItem.get(position));
        Log.i("scheID-----schedule", Integer.toString(sIdItem.size()));
        for(int i = 0; i < sIdItem.size(); i++)
            Log.i("scheID-----forloop", sIdItem.get(i).toString());

        Toast.makeText(getApplicationContext(), nameItem.get(position).toString() + " 세부일정", Toast.LENGTH_SHORT).show();
        startActivity(intent);
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

            for (String str7 : nopItem) {   // 버퍼에 urlItem 쓰기
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

                nameItem.clear();
                sdateItem.clear();
                edateItem.clear();
                bdgtItem.clear();
                mtrlItem.clear();
                nopItem.clear();
                sIdItem.clear();

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
    public void onCreateContextMenu(ContextMenu menu, View view, ContextMenu.ContextMenuInfo menuInfo){
        super.onCreateContextMenu(menu,view,menuInfo);
        menu.setHeaderTitle("일정편집");
        menu.setHeaderIcon(R.drawable.ic_album_black_24dp);
        menu.add(0,1,0,"수정");
        menu.add(0,2,0,"삭제");
        menu.add(0,3,0,"취소");
        m_pos = ((AdapterView.AdapterContextMenuInfo) menuInfo).position;
    }

    public boolean onContextItemSelected(MenuItem item){
        int count;
        count = m_Adapter.getCount();


        switch (item.getItemId()){
            case 1:
                Intent intent = new Intent(Schedule.this, ScheduleAdd.class);
                intent.putExtra("POSITION", m_pos);
                intent.putExtra("ISNEW", false);

                startActivity(intent);
                return true;
            case 2:
                // 삭제할 아이템이 없으면 메시지 출력 후 종료
                if (count == 0) {
                    Toast.makeText(getApplicationContext(), "삭제할 아이템이 없습니다", Toast.LENGTH_SHORT).show();
                    return false;
                }
                int tmp = Integer.parseInt(sIdItem.get(m_pos).toString());
                nameItem.remove(m_pos); // name 아이템 삭제
                sdateItem.remove(m_pos);
                edateItem.remove(m_pos);
                bdgtItem.remove(m_pos);
                mtrlItem.remove(m_pos);
                nopItem.remove(m_pos);
                sIdItem.remove(m_pos);

                ds_db.execSQL("DELETE FROM detailSchedule WHERE schid='"+ tmp + "';");

                m_Adapter.notifyDataSetChanged(); // 리스트뷰 갱신
                saveItemsToFile();  // 리스트뷰 아이템들을 파일에 저장

                return true;
            default:
                return super.onContextItemSelected(item);
        }
    }
}