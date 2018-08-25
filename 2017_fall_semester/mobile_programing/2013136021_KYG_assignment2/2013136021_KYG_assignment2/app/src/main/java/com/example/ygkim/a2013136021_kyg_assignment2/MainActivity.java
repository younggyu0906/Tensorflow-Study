package com.example.ygkim.a2013136021_kyg_assignment2;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.view.ActionMode;
import java.util.ArrayList;
import android.content.Intent;
import android.net.Uri;

import android.widget.Toast;

import java.io.*;

public class MainActivity extends AppCompatActivity implements View.OnLongClickListener, ActionMode.Callback, AdapterView.OnItemLongClickListener{

    static final int GET_STRING = 1;
    private ListView m_ListView;                // listview 선언
    private ArrayAdapter<String> m_Adapter;     // adpater
    private int m_pos;                          // 롱클릭한 리스트 위치를 저장 할 변수
    private ActionMode mActionMode;             // 액션모드 객체 선언

    private final String nameFile = "name.txt";     // 이름을 저장할 파일 이름 선언
    private final String urlFile = "url.txt";       // url을 저장할 파일 이름 선언
    private ArrayList<String> nameItem = new ArrayList<String>();          // name을 저장할 ArrayList
    private ArrayList<String> urlItem = new ArrayList<String>() ;   // url을 저장할 ArrayList

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Android에서 제공하는 String 문자열 하나를 출력하는 layout으로 어댑터 생성
        m_Adapter = new ArrayAdapter<String>(this, android.R.layout.simple_list_item_1, nameItem);

        loadItemsFromFile();                // 파일에서 불러옴
        m_Adapter.notifyDataSetChanged();   // 리스트뷰 갱신

        // Xml에서 추가한 ListView의 객체
        m_ListView = (ListView) findViewById(R.id.list);

        // ListView에 어댑터 연결
        m_ListView.setAdapter(m_Adapter);

        // ListView 아이템 터치 시 이벤트를 처리할 리스너 설정
        m_ListView.setOnItemClickListener(onClickListItem);

        // ListView 아이템 롱클릭 시 이벤트를 처리할 리스너 설정
        m_ListView.setOnItemLongClickListener(this);
    }

    public boolean onCreateOptionsMenu(Menu menu) { // 옵션 메뉴 생성
        MenuInflater inflater = getMenuInflater();
        inflater.inflate(R.menu.mainmenu, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {   // 옵션메뉴선택시
        switch (item.getItemId()) {
            case R.id.add:      // 추가하기 버튼 클릭시
                // Add_bookmark 실행
                Intent in = new Intent(MainActivity.this, Add_bookmark.class);
                startActivityForResult(in, GET_STRING);
                return true;
            default:
                return super.onOptionsItemSelected(item);
        }
    }

    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        if(requestCode == GET_STRING) {
            if(resultCode == RESULT_OK) {
                nameItem.add(data.getStringExtra("NAME_TEXT"));   // 리스트에 문자열 추가
                urlItem.add(data.getStringExtra("URL_TEXT"));      // url아이템에 문자열 추가
                m_Adapter.notifyDataSetChanged();               // 리스트뷰 갱신
                saveItemsToFile();                               // 리스트뷰 아이템들을 파일에 저장
            }
        }
    }

    // 아이템 터치 이벤트 리스너 구현
    private AdapterView.OnItemClickListener onClickListItem = new AdapterView.OnItemClickListener() {
        @Override
        public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
            Intent intent = null;
            intent = new Intent(Intent.ACTION_VIEW, Uri.parse(urlItem.get(position)));
            Toast.makeText(getApplicationContext(), urlItem.get(position), Toast.LENGTH_SHORT).show();

            if(intent != null) {
                if(intent.resolveActivity(getPackageManager()) != null) {
                    startActivity(intent);
                }
            }
        }
    };

    // startActionMode() 메소드가 호출될 때 호출되는 콜백 메소드
    @Override
    public boolean onCreateActionMode(ActionMode mode, Menu menu) {
    // MenuInflater 객체를 이용하여 컨텍스트 메뉴를 생성
        MenuInflater inflater = mode.getMenuInflater();
        inflater.inflate(R.menu.contextmenu, menu);
        return true;
    }

    // onCreateActionMode()가 호출된 후에 호출.
    // 액션 메뉴를 refresh하는 목적으로 여러 번 호출될 수 있음
    @Override
    public boolean onPrepareActionMode(ActionMode mode, Menu menu) { return false; }
    // 아무 것도 하지 않을 때 false 반환, 액션 메뉴가 업데이트 되면 true 반환

    // 사용자가 액션 메뉴 항목을 클릭했을 때 호출
    @Override
    public boolean onActionItemClicked(ActionMode mode, MenuItem item) {
        int count;
        count = m_Adapter.getCount();

        switch (item.getItemId()) {
            case R.id.delete:
                // 삭제할 아이템이 없으면 메시지 출력 후 종료
                if (count == 0) {
                    Toast.makeText(getApplicationContext(), "삭제할 아이템이 없습니다", Toast.LENGTH_SHORT).show();
                    return false;
                }
                nameItem.remove(m_pos); // name 아이템 삭제
                urlItem.remove(m_pos);  // url 아이템 삭제
                m_Adapter.notifyDataSetChanged(); // 리스트뷰 갱신
                saveItemsToFile();  // 리스트뷰 아이템들을 파일에 저장

                mode.finish(); // 컨텍스트 액션 모드를 종료
                return true; // 이벤트를 처리하였으면 true 반환
            default:
                return false;
        }
    }

    // 사용자가 컨텍스트 액션 모드를 빠져나갈 때 호출
    @Override
    public void onDestroyActionMode(ActionMode mode) { mActionMode = null; }

    // View.OnLongClickListener를 구현하기 위해 필요한 콜백 메소드
    public boolean onLongClick(View view) {
        if (mActionMode != null) {
            return false;
        }

        // 컨텍스트 액션 모드 시작
        mActionMode = this.startActionMode(this);
        view.setSelected(true);
        return true;
    }

    @Override
    public boolean onItemLongClick(AdapterView<?> parent, View view, int position, long id) {
        m_pos = position;
        this.onLongClick(view);
        return true;
    }

    // 리스트 뷰 아이템을 파일에 저장
    private void saveItemsToFile() {
        // 파일 객체 선언
        File file = new File(getFilesDir(), nameFile);
        File file2 = new File(getFilesDir(), urlFile);
        // 한 줄 단위로 처리하기 위한 FileWriter 객체 선언
        // FileInputStream은 byte와 char(또는 String)간의 형 변환을 해야함, 버퍼 인덱스의 경계에 따라 타입 변환으로 잘못된 데이터를 가져올 수 있음
        FileWriter fw = null;
        FileWriter fw2 = null;
        // 파일 입출력의 성능을 향상시키기 위한 방법으로 버퍼를 사용한 입출력
        // BufferedWriter 객체 선언
        BufferedWriter bufwr = null;
        BufferedWriter bufwr2 = null;

        try {
            // namefile 파일 열기
            fw = new FileWriter(file);
            bufwr = new BufferedWriter(fw);
            // urlfile 파일 열기
            fw2 = new FileWriter(file2);
            bufwr2 = new BufferedWriter(fw2);

            for (String str : nameItem) {   // 버퍼에 nameItem 쓰기
                bufwr.write(str);              // 문자열 저장
                bufwr.newLine();               // 줄 바꿈
            }

            for (String str2 : urlItem) {   // 버퍼에 urlItem 쓰기
                bufwr2.write(str2) ;              // 문자열 저장
                bufwr2.newLine() ;               // 줄 바꿈
            }

            // write data to the file.
            bufwr.flush();
            bufwr2.flush();

        } catch (Exception e) {
            e.printStackTrace() ;
        }

        try {
            // 파일 닫기
            if (bufwr != null) {
                bufwr.close();
            }

            if (fw != null) {
                fw.close();
            }

            if (bufwr2 != null) {
                bufwr2.close();
            }

            if (fw2 != null) {
                fw2.close();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    // 리스트뷰 아이템을 파일로부터 읽기
    private void loadItemsFromFile() {
        // 파일 객체 선언
        File file = new File(getFilesDir(), nameFile);
        File file2 = new File(getFilesDir(), urlFile);
        // 파일리더 객체 선언
        FileReader fr = null;
        FileReader fr2 = null;
        // 버퍼리더 객체 선언
        BufferedReader bufrd = null;
        BufferedReader bufrd2 = null;
        // 파일로 부터 한 라인을 읽기 위한 String 객체 선언
        String str;
        String str2;

        if (file.exists()) {
            try {
                // 파일 열기
                fr = new FileReader(file);
                bufrd = new BufferedReader(fr);
                fr2 = new FileReader(file2);
                bufrd2 = new BufferedReader(fr2);

                while ((str = bufrd.readLine()) != null) {      // 파일로부터 한 라인 읽기
                    nameItem.add(str);
                }

                while ((str2 = bufrd2.readLine()) != null) {    // 파일로부터 한 라인 읽기
                    urlItem.add(str2);
                }

                // 버퍼리더와 파일리더 닫기
                bufrd.close();
                fr.close();
                bufrd2.close();
                fr2.close();
            } catch (Exception e) {
                e.printStackTrace() ;
            }
        }
    }
}
