package com.example.ygkim.a2013136021_kyg_assignment3;

import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.ServiceConnection;
import android.os.Environment;
import android.os.IBinder;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.ImageButton;
import android.widget.TextView;
import android.widget.Toast;

import java.io.File;

public class musicplay extends AppCompatActivity implements View.OnClickListener {

    ImageButton ib_prev, ib_play, ib_next;
    Button b_exit;
    TextView m_title;

    MusicService mService;
    boolean mBound = false;

    File musicDir;
    File files[] = {};
    int fLength = 0;

    int m_pos;
    boolean isPlay = true;
    boolean isService = false;

    static final String TAG = "KYG_mp3";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_musicplay);

        Intent in = getIntent();
        if(in != null) {
            m_pos = in.getIntExtra("MUSIC_POS", 0);
            isPlay = in.getBooleanExtra("IS_PLAY", false);
            isService = in.getBooleanExtra("IS_SERVICE", false);
        }

        ib_prev = (ImageButton)findViewById(R.id.prev);
        ib_play = (ImageButton)findViewById(R.id.play);
        ib_next = (ImageButton)findViewById(R.id.next);
        b_exit = (Button)findViewById(R.id.exit);
        m_title = (TextView)findViewById(R.id.musicTitle);

        musicDir = Environment.getExternalStoragePublicDirectory(Environment.DIRECTORY_MUSIC);
        files = musicDir.listFiles();
        fLength = files.length;

        m_title.setText(files[m_pos].getName());

        if(isPlay)
            ib_play.setImageResource(android.R.drawable.ic_media_pause);
        else
            ib_play.setImageResource(android.R.drawable.ic_media_play);

        if(!isService) {
            Intent intent = new Intent(this, MusicService.class);
            intent.putExtra("POS", m_pos);
            intent.putExtra("IS_PLAY", isPlay);
            startService(intent);
        }
        Log.d(TAG, "OnCreate isPlay = " + String.valueOf(isPlay));
    }

    // ServiceConnection 인터페이스를 구현한 ServiceConnection 객체 생성
    // onServiceConnected() 콜백 메소드와 onServiceDisconnected() 콜백 메소드를 구현해야 함
    private ServiceConnection mConnection = new ServiceConnection() {

        // Service에 연결(bound)되었을 때 호출되는 callback 메소드
        // Service의 onBind() 메소드에서 반환한 IBinder 객체를 받음 (두번째 인자)
        @Override
        public void onServiceConnected(ComponentName name, IBinder service) {
            Log.d(TAG, "onServiceConnected()");

            // 두번째 인자로 넘어온 IBinder 객체를 LocalService 클래스에 정의된 LocalBinder 클래스 객체로 캐스팅
            MusicService.LocalBinder binder = (MusicService.LocalBinder)service;

            // LocalService 객체를 참조하기 위해 LocalBinder 객체의 getService() 메소드 호출
            mService = binder.getService();

            mBound = true;
        }

        // Service 연결 해제되었을 때 호출되는 callback 메소드
        @Override
        public void onServiceDisconnected(ComponentName name) {
            Log.d(TAG, "onServiceDisconnected()");

            mBound = false;
        }
    };

    @Override
    protected void onStart() {
        super.onStart();

        // 연결할 Service를 위한 Intent 객체 생성
        Intent intent = new Intent(this, MusicService.class);

        // Service에 연결하기 위해 bindService 호출, 생성한 intent 객체와 구현한 ServiceConnection의 객체를 전달
        // boolean bindService(Intent service, ServiceConnection conn, int flags)
        bindService(intent, mConnection, Context.BIND_AUTO_CREATE);
    }

    @Override
    protected void onStop() {
        super.onStop();
        if(mBound) {
            unbindService(mConnection);
            mBound = false;
        }
    }

    // onClick()
    @Override
    public void onClick(View v) {
        switch (v.getId()) {
            case R.id.prev :
                Log.d(TAG, "Prev");
                --m_pos;
                if(m_pos < 0)
                    m_pos = fLength - 1;
                m_title.setText(files[m_pos].getName());
                mService.musicPlay(m_pos);
                break;
            case R.id.next :
                Log.d(TAG, "Next");
                ++m_pos;                    // 위치 +1
                if(m_pos > fLength - 1)    // 위치가 배열의 크기를 벗어나면
                    m_pos = 0;               // 위치 = 0
                m_title.setText(files[m_pos].getName());
                mService.musicPlay(m_pos);  // 재생
                break;
            case R.id.play :
                //play
                if(isPlay) {                // 재생중이면 일시정지
                    Log.d(TAG, "Pause");
                    ib_play.setImageResource(android.R.drawable.ic_media_play);     // 아이콘 변경
                    isPlay = false;         // 재생중이 아님
                    mService.pauseMusic();  // 일시정지
                }
                else {                      // 재생중이 아니면 재생
                    Log.d(TAG, "Play");
                    ib_play.setImageResource(android.R.drawable.ic_media_pause);    // 아이콘 변경
                    isPlay = true;          // 재생중
                    mService.resume();      // 재생
                }
                break;
            case R.id.exit :                // 종료
                //exit
                Toast.makeText(getApplicationContext(), "exit", Toast.LENGTH_SHORT).show();
                Log.d(TAG, "Exit");
                this.onStop();
                stopService(new Intent(this, MusicService.class));
                finish();
                break;
        }
    }
}