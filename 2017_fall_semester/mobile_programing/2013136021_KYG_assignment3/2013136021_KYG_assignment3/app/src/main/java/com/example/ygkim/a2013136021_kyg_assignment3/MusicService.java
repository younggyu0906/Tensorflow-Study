package com.example.ygkim.a2013136021_kyg_assignment3;

import android.app.NotificationManager;
import android.app.PendingIntent;
import android.app.Service;
import android.content.Intent;
import android.media.MediaPlayer;
import android.os.Binder;
import android.os.Environment;
import android.os.IBinder;
import android.support.v4.app.NotificationCompat;
import android.util.Log;
import android.widget.Toast;

import java.io.File;
import java.io.IOException;

public class MusicService extends Service {

    // audio/video 파일 재생을 제어하는데 사용하는 클래스
    MediaPlayer mediaPlayer = null;
    Intent mp_Intent;

    int playLength = 0;     // 음악의 재생 시간. ms

    File musicDir;           // 공유폴더의 경로
    File files[] = {};       // 파일 목록

    int m_pos;               // 재생할 곡의 위치
    boolean isPlay;         // 재생여부

    static final String TAG = "KYG_mp3";

    //------------------- BoundService
    // Binder 클래스를 상속 받는 클래스를 정의
    // getService() 메소드에서 현재 서비스 객체를 반환
    public class LocalBinder extends Binder {
        // 클라이언트가 호출할 수 있는 공개 메소드가 있는 현재 Service 객체 반환
        MusicService getService() {
            return MusicService.this;
        }
    }

    // 위에서 정의한 Binder 클래스의 객체 생성
    // Binder 클래스는 Interface인 IBinder를 구현한 클래스
    private final IBinder mBinder = new LocalBinder();

    // Service 연결이 되었을 때 호출되는 메소드
    @Override
    public IBinder onBind(Intent intent) {
        // TODO: Return the communication channel to the service.
        //throw new UnsupportedOperationException("Not yet implemented");
        return mBinder;
    }

    // 클라이언트가 호출하게 될 메소드
    public void pauseMusic() {
        Toast.makeText(getApplicationContext(), "pause", Toast.LENGTH_SHORT).show();
        isPlay = false;
        mediaPlayer.pause();
        playLength = mediaPlayer.getCurrentPosition();
        KYG_notification();
    }
    public void resume() {
        Toast.makeText(getApplicationContext(), "play", Toast.LENGTH_SHORT).show();
        isPlay = true;
        mediaPlayer.seekTo(playLength);
        mediaPlayer.start();
        KYG_notification();
    }
    // 바인딩된 서비스는 모든 연결이 해제되면 Android 시스템이 서비스를 자동으로 소멸시킴
    // 따라서 서비스가 순전히 바인딩된 서비스인 경우 해당 서비스의 생명주기를 관리하지 않아도 됨

    //-------------------- StartService
    @Override
    public void onCreate() {
        musicDir = Environment.getExternalStoragePublicDirectory(Environment.DIRECTORY_MUSIC);
    }

    @Override
    public int onStartCommand(Intent intent, int flags, int startId) {
        // intent: startService() 호출 시 넘기는 intent 객체
        // flags: service start 요청에 대한 부가 정보. 0, START_FLAG_REDELIVERY, START_FLAG_RETRY
        // startId: start 요청을 나타내는 unique integer id

        Log.d(TAG, "MusicService Start. onStartCommand()");

        if(intent != null) {
            m_pos = intent.getIntExtra("POS", 0);
            isPlay = intent.getBooleanExtra("IS_PLAY", false);
        }

        files = musicDir.listFiles();

        musicPlay(m_pos);

        Log.d(TAG, "Service isPlay = " + String.valueOf(isPlay));

        return START_STICKY;
        //return super.onStartCommand(intent, flags, startId);
    }

    public void KYG_notification() {
        // Notification
        mp_Intent = new Intent(this, musicplay.class);
        mp_Intent.putExtra("IS_PLAY", isPlay);
        mp_Intent.putExtra("MUSIC_POS", m_pos);
        mp_Intent.putExtra("IS_SERVICE", true);
        PendingIntent pIntent = PendingIntent.getActivity(this, 1, mp_Intent, PendingIntent.FLAG_UPDATE_CURRENT);

        NotificationCompat.Builder nBuilder = new NotificationCompat.Builder(this)
                .setSmallIcon(android.R.drawable.ic_media_play)
                .setContentTitle("2013136021_김영규_mp3_Player")
                .setContentIntent(pIntent)
                .setContentText(files[m_pos].getName());
        NotificationManager nManager = (NotificationManager) getSystemService(NOTIFICATION_SERVICE);
        nManager.notify(001, nBuilder.build());
        Log.d(TAG, "Notification");
    }

    @Override
    public void onDestroy() {
        Log.d(TAG, "MusicService stop. onDestroy()");

        // MediaPlayer play 중지
        // MediaPlayer 객체 해제
        super.onDestroy();
        mediaPlayer.release();
        mediaPlayer = null;
    }

    public void musicPlay(int position) {
        if(mediaPlayer != null) {   // 다른 노래를 선택했을 경우나 이전, 다음 노래 선택시 초기화가 필요
            mediaPlayer.release();
            mediaPlayer = null;
        }
        mediaPlayer = new MediaPlayer();
        mediaPlayer.setLooping(true);       // 반복재생 허용
        m_pos = position;

        KYG_notification();

        // MediaPlayer play 시작
        try {
            Log.i(TAG, "Music Path : " + files[position].getAbsolutePath());
            Toast.makeText(getApplicationContext(), files[position].getName(), Toast.LENGTH_SHORT).show();

            // 파일의 절대 경로를 이용하여 MediaPlayer가 재생을 할 mp3 파일을 지정할 수 있다
            // 아래는 files 배열의 첫번째 파일의 절대경로를 알아내고
            // 이를 setDatasource() 메소드에 넘겨주어 해당 파일을 재생할 source로 지정하는 예를 보여주고 있다
            String filepath = files[position].getAbsolutePath();
            mediaPlayer.setDataSource(filepath);

        } catch(IOException e) {
            e.printStackTrace();
        }

        try {
            mediaPlayer.prepare();
        } catch(Exception e) {
            e.printStackTrace();
        }
        mediaPlayer.start();
    }
}