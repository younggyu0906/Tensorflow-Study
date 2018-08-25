package com.example.woogyu.travelrecordsver3;

import android.app.AlertDialog;
import android.app.Dialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteException;
import android.graphics.Color;
import android.graphics.drawable.ColorDrawable;
import android.os.Bundle;
import android.provider.ContactsContract;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v4.app.DialogFragment;
import android.support.v4.app.Fragment;
import android.support.v4.app.FragmentTransaction;
import android.support.v7.app.ActionBar;
import android.util.Log;
import android.view.View;
import android.support.design.widget.NavigationView;
import android.support.v4.view.GravityCompat;
import android.support.v4.widget.DrawerLayout;
import android.support.v7.app.ActionBarDrawerToggle;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.ImageView;
import android.widget.Switch;
import android.widget.Toast;

public class MapEditActivity extends AppCompatActivity
        implements NavigationView.OnNavigationItemSelectedListener {

    //액티비티구분 상수
    private static final int GANGWONDO = 1;
    private static final int CHUNGCHEONGNAMDO = 2;
    private static final int GYEONGSANGNAMDO = 3;

    //컬러구분 상수
    private static final int LAVENDER = 1;
    private static final int ALICEBLUE = 2;
    private static final int IVORY = 3;
    private static final int LEMON = 4;
    private static final int PEACH = 5;
    private static final int MINTCREAM = 6;
    private static final int WHITE = 7;

    int color = WHITE;
    int activity;

    //DB객체
    DBHelper helper;
    SQLiteDatabase db;

    //강원도 지도
    ImageView text_cheorwon;
    ImageView text_chuncheon;
    ImageView text_donghae;
    ImageView text_gangneung;
    ImageView text_gosung;
    ImageView text_hoengsung;
    ImageView text_hongcheon;
    ImageView text_hwacheon;
    ImageView text_injae;
    ImageView text_jeongseon;
    ImageView text_pyeongchang;
    ImageView text_samcheok;
    ImageView text_sokcho;
    ImageView text_taeback;
    ImageView text_wonju;
    ImageView text_yangyang;
    ImageView text_yanggu;
    ImageView text_yeongwol;

    //충청남도 지도
    ImageView map_taean;
    ImageView map_taean2;
    ImageView map_seosan;
    ImageView map_dangjin;
    ImageView map_hongseong;
    ImageView map_yesan;
    ImageView map_asan;
    ImageView map_boryung;
    ImageView map_cheongyang;
    ImageView map_cheonan;
    ImageView map_gongju;
    ImageView map_yeongi;
    ImageView map_seocheon;
    ImageView map_buyeo;
    ImageView map_nonsan;
    ImageView map_gyeryong;
    ImageView map_kumsan;

    //경상남도 지도
    ImageView map_gn_busan;
    ImageView map_gn_changnyeong;
    ImageView map_gn_changwon;
    ImageView map_gn_geochang;
    ImageView map_gn_gosung;
    ImageView map_gn_gujae;
    ImageView map_gn_hadong;
    ImageView map_gn_haman;
    ImageView map_gn_hamyang;
    ImageView map_gn_hapcheon;
    ImageView map_gn_jinju;
    ImageView map_gn_kimhae;
    ImageView map_gn_millyang;
    ImageView map_gn_namhae;
    ImageView map_gn_sacheon;
    ImageView map_gn_sancheong;
    ImageView map_gn_tongyeong;
    ImageView map_gn_uiryeong;
    ImageView map_gn_ulsan;
    ImageView map_gn_yangsan;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_map_edit);

        //DB객체 생성 및 불러오기
        helper = new DBHelper(this);
        try {
            db = helper.getWritableDatabase();
        }catch (SQLiteException ex){
            db = helper.getReadableDatabase();
        }

        //액션바 설정
        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);
        ActionBar actionBar = getSupportActionBar(); //액션바 색깔
        actionBar.setBackgroundDrawable(new ColorDrawable(0xFF424242));

        //슬라이드 메뉴 설정
        DrawerLayout drawer = (DrawerLayout) findViewById(R.id.drawer_layout);
        ActionBarDrawerToggle toggle = new ActionBarDrawerToggle(
                this, drawer, toolbar, R.string.navigation_drawer_open, R.string.navigation_drawer_close);
        drawer.addDrawerListener(toggle);
        toggle.syncState();

        NavigationView navigationView = (NavigationView) findViewById(R.id.nav_view);
        navigationView.setNavigationItemSelectedListener(this);

        //레이아웃 화면 설정
        displaySelectedScreen(activity = getIntent().getIntExtra("ACTIVITY",0));
    }

    private void displaySelectedScreen(int activityId) {
        Fragment fragment = null;

        //선택한 지도에 해당하는 프래그먼트 객체 생성
        switch (activityId) {
            case GANGWONDO:
                fragment = new MapGangwondo();
                break;
            case CHUNGCHEONGNAMDO:
                fragment = new MapChungcheongnamdo();
                break;
            case GYEONGSANGNAMDO:
                fragment = new MapGyeongsangnamdo();
               break;
        }

        if (fragment != null) {
            FragmentTransaction ft = getSupportFragmentManager().beginTransaction();
            ft.replace(R.id.content_frame, fragment);
            ft.commit();
        }

        DrawerLayout drawer = (DrawerLayout) findViewById(R.id.drawer_layout);
        drawer.closeDrawer(GravityCompat.START);
    }

    @Override
    protected void onResume(){
        super.onResume();
        settingsMap();
    }

    @Override
    public void onBackPressed() {
        DrawerLayout drawer = (DrawerLayout) findViewById(R.id.drawer_layout);
        if (drawer.isDrawerOpen(GravityCompat.START)) {
            drawer.closeDrawer(GravityCompat.START);
        } else {
            super.onBackPressed();
        }
    }



    //옵션메뉴
    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.map_edit, menu);
        return true;
    }
    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        int id = item.getItemId();

        if (id == R.id.action_exit) {
            finish();
            return true;
        }
        else if(id == R.id.action_clear){
            DialogInterface.OnClickListener yesListener = new DialogInterface.OnClickListener() {
                @Override
                public void onClick(DialogInterface dialog, int which) {
                    color = WHITE;
                    if(activity == GANGWONDO) {
                        paintingMap("철원", text_cheorwon, false);
                        paintingMap("춘천", text_chuncheon, false);
                        paintingMap("동해", text_donghae, false);
                        paintingMap("강릉", text_gangneung, false);
                        paintingMap("고성", text_gosung, false);
                        paintingMap("횡성", text_hoengsung, false);
                        paintingMap("홍천", text_hongcheon, false);
                        paintingMap("화천", text_hwacheon, false);
                        paintingMap("인제", text_injae, false);
                        paintingMap("정선", text_jeongseon, false);
                        paintingMap("평창", text_pyeongchang, false);
                        paintingMap("삼척", text_samcheok, false);
                        paintingMap("속초", text_sokcho, false);
                        paintingMap("태백", text_taeback, false);
                        paintingMap("원주", text_wonju, false);
                        paintingMap("양구", text_yanggu, false);
                        paintingMap("양양", text_yangyang, false);
                        paintingMap("영월", text_yeongwol, false);
                    }
                    else if(activity == CHUNGCHEONGNAMDO){
                        paintingMap("태안", map_taean, false);
                        paintingMap("태안", map_taean2, false);
                        paintingMap("서산", map_seosan, false);
                        paintingMap("당진", map_dangjin, false);
                        paintingMap("홍성", map_hongseong, false);
                        paintingMap("예산", map_yesan, false);
                        paintingMap("아산", map_asan, false);
                        paintingMap("보령", map_boryung, false);
                        paintingMap("청양", map_cheongyang, false);
                        paintingMap("천안", map_cheonan, false);
                        paintingMap("공주", map_gongju, false);
                        paintingMap("연기", map_yeongi, false);
                        paintingMap("서천", map_seocheon, false);
                        paintingMap("부여", map_buyeo, false);
                        paintingMap("논산", map_nonsan, false);
                        paintingMap("계룡", map_gyeryong, false);
                        paintingMap("금산", map_kumsan, false);
                    }
                    else if(activity == GYEONGSANGNAMDO){
                        paintingMap("부산", map_gn_busan, false);
                        paintingMap("창녕", map_gn_changnyeong, false);
                        paintingMap("창원", map_gn_changwon, false);
                        paintingMap("거창", map_gn_geochang, false);
                        paintingMap("고성", map_gn_gosung, false);
                        paintingMap("거제", map_gn_gujae, false);
                        paintingMap("하동", map_gn_hadong, false);
                        paintingMap("함안", map_gn_haman, false);
                        paintingMap("함양", map_gn_hamyang, false);
                        paintingMap("합천", map_gn_hapcheon, false);
                        paintingMap("진주", map_gn_jinju, false);
                        paintingMap("김해", map_gn_kimhae, false);
                        paintingMap("밀양", map_gn_millyang, false);
                        paintingMap("남해", map_gn_namhae, false);
                        paintingMap("사천", map_gn_sacheon, false);
                        paintingMap("산청", map_gn_sancheong, false);
                        paintingMap("통영", map_gn_tongyeong, false);
                        paintingMap("의령", map_gn_uiryeong, false);
                        paintingMap("울산", map_gn_ulsan, false);
                        paintingMap("양산", map_gn_yangsan, false);
                    }
                }
            };
            DialogInterface.OnClickListener noListener = new DialogInterface.OnClickListener() {
                @Override
                public void onClick(DialogInterface dialog, int which) {
                    dialog.dismiss();
                }
            };
            new AlertDialog.Builder(this)
                    .setTitle("초기화 하시겠습니까?")
                    .setIcon(R.drawable.ic_info_black_24dp)
                    .setPositiveButton("확인", yesListener)
                    .setNegativeButton("취소", noListener)
                    .show();

            return true;
        }

        return super.onOptionsItemSelected(item);
    }

    @SuppressWarnings("StatementWithEmptyBody")
    @Override
    public boolean onNavigationItemSelected(MenuItem item) {
        int id = item.getItemId();

        if (id == R.id.nav_Lavender) {
            color = LAVENDER;
        } else if (id == R.id.nav_AliceBlue) {
            color = ALICEBLUE;
        } else if (id == R.id.nav_Ivory) {
            color = IVORY;
        } else if (id == R.id.nav_Lemon) {
            color = LEMON;
        } else if (id == R.id.nav_Peach) {
            color = PEACH;
        } else if (id == R.id.nav_MintCream) {
            color = MINTCREAM;
        } else if (id == R.id.nav_White) {
            color = WHITE;
        }

        DrawerLayout drawer = (DrawerLayout) findViewById(R.id.drawer_layout);
        drawer.closeDrawer(GravityCompat.START);
        return true;
    }
    public void settingsMap(){
        String name;

        //강원도 맵 셋팅
        if(activity == GANGWONDO) {
            text_cheorwon = (ImageView) findViewById(R.id.map_cheorwon2);
            text_chuncheon = (ImageView) findViewById(R.id.map_chuncheon2);
            text_donghae = (ImageView) findViewById(R.id.map_donghae2);
            text_gangneung = (ImageView) findViewById(R.id.map_gangneung2);
            text_gosung = (ImageView) findViewById(R.id.map_gosung2);
            text_hoengsung = (ImageView) findViewById(R.id.map_hoengseong2);
            text_hongcheon = (ImageView) findViewById(R.id.map_hongcheon2);
            text_hwacheon = (ImageView) findViewById(R.id.map_hwacheon2);
            text_injae = (ImageView) findViewById(R.id.map_injae2);
            text_jeongseon = (ImageView) findViewById(R.id.map_jeongseon2);
            text_pyeongchang = (ImageView) findViewById(R.id.map_pyeongchang2);
            text_samcheok = (ImageView) findViewById(R.id.map_samcheok2);
            text_sokcho = (ImageView) findViewById(R.id.map_sokcho2);
            text_taeback = (ImageView) findViewById(R.id.map_taebaek2);
            text_wonju = (ImageView) findViewById(R.id.map_wonju2);
            text_yangyang = (ImageView) findViewById(R.id.map_yangyang2);
            text_yanggu = (ImageView) findViewById(R.id.map_yanggu2);
            text_yeongwol = (ImageView) findViewById(R.id.map_yeongwol2);

            name = "철원";
            paintingMap(name, text_cheorwon, true);
            name = "춘천";
            paintingMap(name, text_chuncheon, true);
            name = "동해";
            paintingMap(name, text_donghae, true);
            name = "강릉";
            paintingMap(name, text_gangneung, true);
            name = "고성";
            paintingMap(name, text_gosung, true);
            name = "횡성";
            paintingMap(name, text_hoengsung, true);
            name = "홍천";
            paintingMap(name, text_hongcheon, true);
            name = "화천";
            paintingMap(name, text_hwacheon, true);
            name = "인제";
            paintingMap(name, text_injae, true);
            name = "정선";
            paintingMap(name, text_jeongseon, true);
            name = "평창";
            paintingMap(name, text_pyeongchang, true);
            name = "삼척";
            paintingMap(name, text_samcheok, true);
            name = "속초";
            paintingMap(name, text_sokcho, true);
            name = "태백";
            paintingMap(name, text_taeback, true);
            name = "원주";
            paintingMap(name, text_wonju, true);
            name = "양구";
            paintingMap(name, text_yanggu, true);
            name = "양양";
            paintingMap(name, text_yangyang, true);
            name = "영월";
            paintingMap(name, text_yeongwol, true);
        }
        //충청남도 맵 셋팅
        else if(activity == CHUNGCHEONGNAMDO){
            map_taean = (ImageView)findViewById(R.id.map_cn_taean2);
            map_taean2 = (ImageView)findViewById(R.id.map_cn_taean2_2);
            map_seosan = (ImageView)findViewById(R.id.map_cn_seosan2);
            map_dangjin = (ImageView)findViewById(R.id.map_cn_dangjin2);
            map_hongseong = (ImageView)findViewById(R.id.map_cn_hongseong2);
            map_yesan = (ImageView)findViewById(R.id.map_cn_yesan2);
            map_asan = (ImageView)findViewById(R.id.map_cn_asan2);
            map_boryung = (ImageView)findViewById(R.id.map_cn_boryung2);
            map_cheongyang = (ImageView)findViewById(R.id.map_cn_cheongyang2);
            map_cheonan = (ImageView)findViewById(R.id.map_cn_cheonan2);
            map_gongju = (ImageView)findViewById(R.id.map_cn_gongju2);
            map_yeongi = (ImageView)findViewById(R.id.map_cn_yeongi2);
            map_seocheon = (ImageView)findViewById(R.id.map_cn_seocheon2);
            map_buyeo = (ImageView)findViewById(R.id.map_cn_buyeo2);
            map_nonsan = (ImageView)findViewById(R.id.map_cn_nonsan2);
            map_gyeryong = (ImageView)findViewById(R.id.map_cn_gyeryong2);
            map_kumsan = (ImageView)findViewById(R.id.map_cn_kumsan2);

            name = "태안";
            paintingMap(name, map_taean, true);
            paintingMap(name, map_taean2, true);
            name = "서산";
            paintingMap(name, map_seosan, true);
            name = "당진";
            paintingMap(name, map_dangjin, true);
            name = "홍성";
            paintingMap(name, map_hongseong, true);
            name = "예산";
            paintingMap(name, map_yesan, true);
            name = "아산";
            paintingMap(name, map_asan, true);
            name = "보령";
            paintingMap(name, map_boryung, true);
            name = "청양";
            paintingMap(name, map_cheongyang, true);
            name = "천안";
            paintingMap(name, map_cheonan, true);
            name = "공주";
            paintingMap(name, map_gongju, true);
            name = "연기";
            paintingMap(name, map_yeongi, true);
            name = "서천";
            paintingMap(name, map_seocheon, true);
            name = "부여";
            paintingMap(name, map_buyeo, true);
            name = "논산";
            paintingMap(name, map_nonsan, true);
            name = "계룡";
            paintingMap(name, map_gyeryong, true);
            name = "금산";
            paintingMap(name, map_kumsan, true);
        }
        //경상남도 맵 셋팅
        else if(activity == GYEONGSANGNAMDO){
            map_gn_busan = (ImageView)findViewById(R.id.map_gn_busan2);
            map_gn_changnyeong = (ImageView)findViewById(R.id.map_gn_changnyeong2);
            map_gn_changwon = (ImageView)findViewById(R.id.map_gn_changwon2);
            map_gn_geochang = (ImageView)findViewById(R.id.map_gn_geochang2);
            map_gn_gosung = (ImageView)findViewById(R.id.map_gn_gosung2);
            map_gn_gujae = (ImageView)findViewById(R.id.map_gn_gujae2);
            map_gn_hadong = (ImageView)findViewById(R.id.map_gn_hadong2);
            map_gn_haman = (ImageView)findViewById(R.id.map_gn_haman2);
            map_gn_hamyang = (ImageView)findViewById(R.id.map_gn_hamyang2);
            map_gn_hapcheon = (ImageView)findViewById(R.id.map_gn_hapcheon2);
            map_gn_jinju = (ImageView)findViewById(R.id.map_gn_jinju2);
            map_gn_kimhae = (ImageView)findViewById(R.id.map_gn_kimhae2);
            map_gn_millyang = (ImageView)findViewById(R.id.map_gn_millyang2);
            map_gn_namhae = (ImageView)findViewById(R.id.map_gn_namhae2);
            map_gn_sacheon = (ImageView)findViewById(R.id.map_gn_sacheon2);
            map_gn_sancheong = (ImageView)findViewById(R.id.map_gn_sancheong2);
            map_gn_tongyeong = (ImageView)findViewById(R.id.map_gn_tongyeong2);
            map_gn_uiryeong = (ImageView)findViewById(R.id.map_gn_uiryeong2);
            map_gn_ulsan = (ImageView)findViewById(R.id.map_gn_ulsan2);
            map_gn_yangsan = (ImageView)findViewById(R.id.map_gn_yangsan2);

            name = "부산";
            paintingMap(name, map_gn_busan, true);
            name = "창녕";
            paintingMap(name, map_gn_changnyeong, true);
            name = "창원";
            paintingMap(name, map_gn_changwon, true);
            name = "거창";
            paintingMap(name, map_gn_geochang, true);
            name = "고성";
            paintingMap(name, map_gn_gosung, true);
            name = "거제";
            paintingMap(name, map_gn_gujae, true);
            name = "하동";
            paintingMap(name, map_gn_hadong, true);
            name = "함안";
            paintingMap(name, map_gn_haman, true);
            name = "함양";
            paintingMap(name, map_gn_hamyang, true);
            name = "합천";
            paintingMap(name, map_gn_hapcheon, true);
            name = "진주";
            paintingMap(name, map_gn_jinju, true);
            name = "김해";
            paintingMap(name, map_gn_kimhae, true);
            name = "밀양";
            paintingMap(name, map_gn_millyang, true);
            name = "남해";
            paintingMap(name, map_gn_namhae, true);
            name = "사천";
            paintingMap(name, map_gn_sacheon, true);
            name = "산청";
            paintingMap(name, map_gn_sancheong, true);
            name = "통영";
            paintingMap(name, map_gn_tongyeong, true);
            name = "의령";
            paintingMap(name, map_gn_uiryeong, true);
            name = "울산";
            paintingMap(name, map_gn_ulsan, true);
            name = "양산";
            paintingMap(name, map_gn_yangsan, true);
        }
    }

    public void onClick(View view){
        Log.i("onclick","--->ok");
        if(activity == GANGWONDO) {
            switch (view.getId()) {
                case R.id.name_cheorwon2:
                    paintingMap("철원", text_cheorwon, false);
                    break;
                case R.id.name_chuncheon2:
                    paintingMap("춘천", text_chuncheon, false);
                    break;
                case R.id.name_donghae2:
                    paintingMap("동해", text_donghae, false);
                    break;
                case R.id.name_gangneung2:
                    paintingMap("강릉", text_gangneung, false);
                    break;
                case R.id.name_gosung2:
                    paintingMap("고성", text_gosung, false);
                    break;
                case R.id.name_hoengsung2:
                    paintingMap("횡성", text_hoengsung, false);
                    break;
                case R.id.name_hongcheon2:
                    paintingMap("홍천", text_hongcheon, false);
                    break;
                case R.id.name_hwacheon2:
                    paintingMap("화천", text_hwacheon, false);
                    break;
                case R.id.name_injae2:
                    paintingMap("인제", text_injae, false);
                    break;
                case R.id.name_jeongseon2:
                    paintingMap("정선", text_jeongseon, false);
                    break;
                case R.id.name_pyeongchang2:
                    paintingMap("평창", text_pyeongchang, false);
                    break;
                case R.id.name_samcheok2:
                    paintingMap("삼척", text_samcheok, false);
                    break;
                case R.id.name_sokcho2:
                    paintingMap("속초", text_sokcho, false);
                    break;
                case R.id.name_taeback2:
                    paintingMap("태백", text_taeback, false);
                    break;
                case R.id.name_wonju2:
                    paintingMap("원주", text_wonju, false);
                    break;
                case R.id.name_yanggu2:
                    paintingMap("양구", text_yanggu, false);
                    break;
                case R.id.name_yangyang2:
                    paintingMap("양양", text_yangyang, false);
                    break;
                case R.id.name_yeongwol2:
                    paintingMap("영월", text_yeongwol, false);
                    break;
            }
        }
        else if(activity == CHUNGCHEONGNAMDO){
            switch (view.getId()) {
                case R.id.name_cn_taean2 :
                    paintingMap("태안", map_taean, false);
                    paintingMap("태안", map_taean2, false);
                    break;
                case R.id.name_cn_seosan2 :
                    paintingMap("서산", map_seosan, false);
                    break;
                case R.id.name_cn_dangjin2 :
                    paintingMap("당진", map_dangjin, false);
                    break;
                case R.id.name_cn_hongseong2 :
                    paintingMap("홍성", map_hongseong, false);
                    break;
                case R.id.name_cn_yesan2 :
                    paintingMap("예산", map_yesan, false);
                    break;
                case R.id.name_cn_asan2 :
                    paintingMap("아산", map_asan, false);
                    break;
                case R.id.name_cn_boryung2 :
                    paintingMap("보령", map_boryung, false);
                    break;
                case R.id.name_cn_cheongyang2 :
                    paintingMap("청양", map_cheongyang, false);
                    break;
                case R.id.name_cn_cheonan2 :
                    paintingMap("천안", map_cheonan, false);
                    break;
                case R.id.name_cn_gongju2 :
                    paintingMap("공주", map_gongju, false);
                    break;
                case R.id.name_cn_yeongi2 :
                    paintingMap("연기", map_yeongi, false);
                    break;
                case R.id.name_cn_seocheon2 :
                    paintingMap("서천", map_seocheon, false);
                    break;
                case R.id.name_cn_buyeo2 :
                    paintingMap("부여", map_buyeo, false);
                    break;
                case R.id.name_cn_nonsan2 :
                    paintingMap("논산", map_nonsan, false);
                    break;
                case R.id.name_cn_gyeryong2 :
                    paintingMap("계룡", map_gyeryong, false);
                    break;
                case R.id.name_cn_kumsan2 :
                    paintingMap("금산", map_kumsan, false);
                    break;
            }
        }
        else if(activity == GYEONGSANGNAMDO){
            switch (view.getId()) {
                case R.id.name_gn_busan2 :
                    paintingMap("부산", map_gn_busan, false);
                    break;
                case R.id.name_gn_changnyeong2 :
                    paintingMap("창녕", map_gn_changnyeong, false);
                    break;
                case R.id.name_gn_changwon2 :
                    paintingMap("창원", map_gn_changwon, false);
                    break;
                case R.id.name_gn_geochang2 :
                    paintingMap("거창", map_gn_geochang, false);
                    break;
                case R.id.name_gn_gosung2 :
                    paintingMap("고성", map_gn_gosung, false);
                    break;
                case R.id.name_gn_gujae2 :
                    paintingMap("거제", map_gn_gujae, false);
                    break;
                case R.id.name_gn_hadong2 :
                    paintingMap("하동", map_gn_hadong, false);
                    break;
                case R.id.name_gn_haman2 :
                    paintingMap("함안", map_gn_haman, false);
                    break;
                case R.id.name_gn_hamyang2 :
                    paintingMap("함양", map_gn_hamyang, false);
                    break;
                case R.id.name_gn_hapcheon2 :
                    paintingMap("합천", map_gn_hapcheon, false);
                    break;
                case R.id.name_gn_jinju2 :
                    paintingMap("진주", map_gn_jinju, false);
                    break;
                case R.id.name_gn_kimhae2 :
                    paintingMap("김해", map_gn_kimhae, false);
                    break;
                case R.id.name_gn_millyang2 :
                    paintingMap("밀양", map_gn_millyang, false);
                    break;
                case R.id.name_gn_namhae2 :
                    paintingMap("남해", map_gn_namhae, false);
                    break;
                case R.id.name_gn_sacheon2 :
                    paintingMap("사천", map_gn_sacheon, false);
                    break;
                case R.id.name_gn_sancheong2 :
                    paintingMap("산청", map_gn_sancheong, false);
                    break;
                case R.id.name_gn_tongyeong2 :
                    paintingMap("통영", map_gn_tongyeong, false);
                    break;
                case R.id.name_gn_uiryeong2 :
                    paintingMap("의령", map_gn_uiryeong, false);
                    break;
                case R.id.name_gn_ulsan2 :
                    paintingMap("울산", map_gn_ulsan, false);
                    break;
                case R.id.name_gn_yangsan2 :
                    paintingMap("양산", map_gn_yangsan, false);
                    break;
            }
        }
    }

    public void paintingMap(String name, ImageView image, boolean isFirst){
        Cursor cursor;

        if(isFirst) {
            if(activity == GANGWONDO) {
                cursor = db.rawQuery("SELECT name, color FROM gangwondo WHERE name='" + name + "';", null);
            }
            else if(activity == CHUNGCHEONGNAMDO){
                cursor = db.rawQuery("SELECT name, color FROM chungcheongnamdo WHERE name='" + name + "';", null);
            }
            else if(activity == GYEONGSANGNAMDO){
                cursor = db.rawQuery("SELECT name, color FROM gyeongsangnamdo WHERE name='" + name + "';", null);
                cursor.moveToFirst();
                Log.i("test-->",cursor.getString(0)+" : "+cursor.getString(1));
            }
            else
                cursor = db.rawQuery("SELECT name, color FROM gangwondo WHERE name='" + name + "';", null);

            if(cursor.getCount()>0) {
                cursor.moveToFirst();
                switch (cursor.getString(1)){
                    case "Lavender" :
                        image.setColorFilter(Color.argb(255,230,230,250));
                        break;
                    case "AliceBlue" :
                        image.setColorFilter(Color.argb(255,240,248,250));
                        break;
                    case "Ivory" :
                        image.setColorFilter(Color.argb(255,255,255,240));
                        break;
                    case "Lemon" :
                        image.setColorFilter(Color.argb(255,255,250,205));
                        break;
                    case "Peach" :
                        image.setColorFilter(Color.argb(255,255,218,185));
                        break;
                    case "MintCream" :
                        image.setColorFilter(Color.argb(255,245,255,250));
                        break;
                    default :
                        image.clearColorFilter();
                }
            }
        }
        else{
            String colorName;
            switch (color){
                case LAVENDER :
                    image.setColorFilter(Color.argb(255,230,230,250));
                    colorName = "Lavender";
                    break;
                case ALICEBLUE :
                    image.setColorFilter(Color.argb(255,240,248,250));
                    colorName = "AliceBlue";
                    break;
                case IVORY :
                    image.setColorFilter(Color.argb(255,255,255,240));
                    colorName = "Ivory";
                    break;
                case LEMON :
                    image.setColorFilter(Color.argb(255,255,250,205));
                    colorName = "Lemon";
                    break;
                case PEACH :
                    image.setColorFilter(Color.argb(255,255,218,185));
                    colorName = "Peach";
                    break;
                case MINTCREAM :
                    image.setColorFilter(Color.argb(255,245,255,250));
                    colorName = "MintCream";
                    break;
                default :
                    image.clearColorFilter();
                    colorName = "WHITE";
            }

            if(activity == GANGWONDO)
                db.execSQL("UPDATE gangwondo SET color='"+colorName+"'WHERE name='"+name+"';");
            else if(activity == CHUNGCHEONGNAMDO)
                db.execSQL("UPDATE chungcheongnamdo SET color='"+colorName+"'WHERE name='"+name+"';");
            else if(activity == GYEONGSANGNAMDO)
                db.execSQL("UPDATE gyeongsangnamdo SET color='"+colorName+"'WHERE name='"+name+"';");
        }
    }
    @Override
    protected void onPause(){
        super.onPause();
        Intent intent = new Intent();
        setResult(RESULT_CANCELED,intent);
    }
}

