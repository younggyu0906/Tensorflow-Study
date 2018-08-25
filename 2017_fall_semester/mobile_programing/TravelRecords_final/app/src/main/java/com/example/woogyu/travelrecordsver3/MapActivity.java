package com.example.woogyu.travelrecordsver3;

import android.content.Intent;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteException;
import android.graphics.Color;
import android.graphics.drawable.ColorDrawable;
import android.support.design.widget.TabLayout;
import android.support.v7.app.ActionBar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;

import android.support.v4.app.Fragment;
import android.support.v4.app.FragmentManager;
import android.support.v4.app.FragmentPagerAdapter;
import android.support.v4.view.ViewPager;
import android.os.Bundle;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;

import android.widget.ImageView;

public class MapActivity extends AppCompatActivity {

    private SectionsPagerAdapter mSectionsPagerAdapter;

    private ViewPager mViewPager;
    TabLayout tabLayout;
    ActionBar actionBar;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_map);

        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar); //액션바 설정
        setSupportActionBar(toolbar);

        actionBar = getSupportActionBar(); //액션바 색깔
        actionBar.setBackgroundDrawable(new ColorDrawable(0xFF448AFF));

        mSectionsPagerAdapter = new SectionsPagerAdapter(getSupportFragmentManager());

        mViewPager = (ViewPager) findViewById(R.id.container);
        mViewPager.setAdapter(mSectionsPagerAdapter);

        tabLayout = (TabLayout) findViewById(R.id.tabs);

        mViewPager.addOnPageChangeListener(new TabLayout.TabLayoutOnPageChangeListener(tabLayout));
        tabLayout.addOnTabSelectedListener(new TabLayout.ViewPagerOnTabSelectedListener(mViewPager));

        isEdit = false;

    }

    //옵션메뉴
    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.menu_map, menu);
        return true;
    }
    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        int id = item.getItemId();

        if (id == R.id.action_exit) {
            finish();
            return true;
        }
        else if(id == R.id.action_painting1 || id == R.id.action_painting2){
            Intent intent = new Intent(this,MapEditActivity.class);
            intent.putExtra("ACTIVITY",mViewPager.getCurrentItem() + 1);
            startActivityForResult(intent,0);
            return true;
        }
        return super.onOptionsItemSelected(item);
    }
    boolean isEdit;
    @Override
    protected void onActivityResult(int requstCode, int resultCode, Intent data){
       if(requstCode == 0){
           if(resultCode == RESULT_CANCELED){
               isEdit = true;
               Log.i("Map-->","RESULT CANCELED");
               finish();
            }
            else
                isEdit = false;
        }
    }
    @Override
    protected void onPause(){
        super.onPause();

        Intent intent = new Intent();
        if(isEdit) {
            setResult(RESULT_CANCELED,intent);
            Log.i("onDestroy() -->","result cancel!");
        }
        else {
            setResult(RESULT_OK,intent);
            Log.i("onDestroy() -->","result okl!");
        }
    }

    public static class PlaceholderFragment extends Fragment {

        private static final String ARG_SECTION_NUMBER = "section_number";
        View rootView;

        public PlaceholderFragment() {
        }

        public static PlaceholderFragment newInstance(int sectionNumber) {
            PlaceholderFragment fragment = new PlaceholderFragment();
            Bundle args = new Bundle();
            args.putInt(ARG_SECTION_NUMBER, sectionNumber);
            fragment.setArguments(args);
            return fragment;
        }

        DBHelper helper;
        SQLiteDatabase db;
        private static final int GANGWONDO = 1;
        private static final int CHUNGCHEONGNAMDO = 2;
        private static final int GYEONGSANGNAMDO = 3;
        int activity;

        @Override
        public View onCreateView(LayoutInflater inflater, ViewGroup container,
                                 Bundle savedInstanceState) {

            //디비 생성 및 불러오기
            helper = new DBHelper(getContext());
            try {
                db = helper.getWritableDatabase();
            }catch (SQLiteException ex){
                db = helper.getReadableDatabase();
            }

            //지도뷰생성
            switch (getArguments().getInt(ARG_SECTION_NUMBER)){
                case GANGWONDO :
                    rootView = inflater.inflate(R.layout.gangwondo_map,container,false);
                    activity = GANGWONDO;
                    setGangwondo();
                    return rootView;
                case CHUNGCHEONGNAMDO :
                    rootView = inflater.inflate(R.layout.chungcheongnamdo_map, container, false);
                    activity = CHUNGCHEONGNAMDO;
                    setChungcheongnamdo();
                    return rootView;
                case GYEONGSANGNAMDO:
                    rootView = inflater.inflate(R.layout.gyeongsangnamdo_map, container, false);
                    activity = GYEONGSANGNAMDO;
                    setGyeongsangnamdo();
                    return rootView;
                default:
                    rootView = inflater.inflate(R.layout.gangwondo_map, container, false);
                    return rootView;
            }
        }

        public void setGangwondo(){
            ImageView text_cheorwon = (ImageView)rootView.findViewById(R.id.map_cheorwon);
            ImageView text_chuncheon = (ImageView)rootView.findViewById(R.id.map_chuncheon);
            ImageView text_donghae = (ImageView)rootView.findViewById(R.id.map_donghae);
            ImageView text_gangneung = (ImageView)rootView.findViewById(R.id.map_gangneung);
            ImageView text_gosung = (ImageView)rootView.findViewById(R.id.map_gosung);
            ImageView text_hoengsung = (ImageView)rootView.findViewById(R.id.map_hoengseong);
            ImageView text_hongcheon = (ImageView)rootView.findViewById(R.id.map_hongcheon);
            ImageView text_hwacheon = (ImageView)rootView.findViewById(R.id.map_hwacheon);
            ImageView text_injae = (ImageView)rootView.findViewById(R.id.map_injae);
            ImageView text_jeongseon = (ImageView)rootView.findViewById(R.id.map_jeongseon);
            ImageView text_pyeongchang = (ImageView)rootView.findViewById(R.id.map_pyeongchang);
            ImageView text_samcheok = (ImageView)rootView.findViewById(R.id.map_samcheok);
            ImageView text_sokcho = (ImageView)rootView.findViewById(R.id.map_sokcho);
            ImageView text_taeback = (ImageView)rootView.findViewById(R.id.map_taebaek);
            ImageView text_wonju = (ImageView)rootView.findViewById(R.id.map_wonju);
            ImageView text_yangyang = (ImageView)rootView.findViewById(R.id.map_yangyang);
            ImageView text_yanggu = (ImageView)rootView.findViewById(R.id.map_yanggu);
            ImageView text_yeongwol = (ImageView)rootView.findViewById(R.id.map_yeongwol);

            String name;

            name = "철원";
            paintingMap(name,text_cheorwon);
            name = "춘천";
            paintingMap(name,text_chuncheon);
            name = "동해";
            paintingMap(name,text_donghae);
            name = "강릉";
            paintingMap(name,text_gangneung);
            name = "고성";
            paintingMap(name,text_gosung);
            name = "횡성";
            paintingMap(name,text_hoengsung);
            name = "홍천";
            paintingMap(name,text_hongcheon);
            name = "화천";
            paintingMap(name,text_hwacheon);
            name = "인제";
            paintingMap(name,text_injae);
            name = "정선";
            paintingMap(name,text_jeongseon);
            name = "평창";
            paintingMap(name,text_pyeongchang);
            name = "삼척";
            paintingMap(name,text_samcheok);
            name = "속초";
            paintingMap(name,text_sokcho);
            name = "태백";
            paintingMap(name,text_taeback);
            name = "원주";
            paintingMap(name,text_wonju);
            name = "양구";
            paintingMap(name,text_yanggu);
            name = "양양";
            paintingMap(name,text_yangyang);
            name = "영월";
            paintingMap(name,text_yeongwol);
        }

        public void setChungcheongnamdo(){
            ImageView map_taean = (ImageView)rootView.findViewById(R.id.map_cn_taean);
            ImageView map_taean2 = (ImageView)rootView.findViewById(R.id.map_cn_taean2);
            ImageView map_seosan = (ImageView)rootView.findViewById(R.id.map_cn_seosan);
            ImageView map_dangjin = (ImageView)rootView.findViewById(R.id.map_cn_dangjin);
            ImageView map_hongseong = (ImageView)rootView.findViewById(R.id.map_cn_hongseong);
            ImageView map_yesan = (ImageView)rootView.findViewById(R.id.map_cn_yesan);
            ImageView map_asan = (ImageView)rootView.findViewById(R.id.map_cn_asan);
            ImageView map_boryung = (ImageView)rootView.findViewById(R.id.map_cn_boryung);
            ImageView map_cheongyang = (ImageView)rootView.findViewById(R.id.map_cn_cheongyang);
            ImageView map_cheonan = (ImageView)rootView.findViewById(R.id.map_cn_cheonan);
            ImageView map_gongju = (ImageView)rootView.findViewById(R.id.map_cn_gongju);
            ImageView map_yeongi = (ImageView)rootView.findViewById(R.id.map_cn_yeongi);
            ImageView map_seocheon = (ImageView)rootView.findViewById(R.id.map_cn_seocheon);
            ImageView map_buyeo = (ImageView)rootView.findViewById(R.id.map_cn_buyeo);
            ImageView map_nonsan = (ImageView)rootView.findViewById(R.id.map_cn_nonsan);
            ImageView map_gyeryong = (ImageView)rootView.findViewById(R.id.map_cn_gyeryong);
            ImageView map_kumsan = (ImageView)rootView.findViewById(R.id.map_cn_kumsan);

            String name;

            name = "태안";
            paintingMap(name, map_taean);
            paintingMap(name, map_taean2);
            name = "서산";
            paintingMap(name, map_seosan);
            name = "당진";
            paintingMap(name, map_dangjin);
            name = "홍성";
            paintingMap(name, map_hongseong);
            name = "예산";
            paintingMap(name, map_yesan);
            name = "아산";
            paintingMap(name, map_asan);
            name = "보령";
            paintingMap(name, map_boryung);
            name = "청양";
            paintingMap(name, map_cheongyang);
            name = "천안";
            paintingMap(name, map_cheonan);
            name = "공주";
            paintingMap(name, map_gongju);
            name = "연기";
            paintingMap(name, map_yeongi);
            name = "서천";
            paintingMap(name, map_seocheon);
            name = "부여";
            paintingMap(name, map_buyeo);
            name = "논산";
            paintingMap(name, map_nonsan);
            name = "계룡";
            paintingMap(name, map_gyeryong);
            name = "금산";
            paintingMap(name, map_kumsan);
        }

        public void setGyeongsangnamdo(){
            ImageView map_gn_busan = (ImageView)rootView.findViewById(R.id.map_gn_busan);
            ImageView map_gn_changnyeong = (ImageView)rootView.findViewById(R.id.map_gn_changnyeong);
            ImageView map_gn_changwon = (ImageView)rootView.findViewById(R.id.map_gn_changwon);
            ImageView map_gn_geochang = (ImageView)rootView.findViewById(R.id.map_gn_geochang);
            ImageView map_gn_gosung = (ImageView)rootView.findViewById(R.id.map_gn_gosung);
            ImageView map_gn_gujae = (ImageView)rootView.findViewById(R.id.map_gn_gujae);
            ImageView map_gn_hadong = (ImageView)rootView.findViewById(R.id.map_gn_hadong);
            ImageView map_gn_haman = (ImageView)rootView.findViewById(R.id.map_gn_haman);
            ImageView map_gn_hamyang = (ImageView)rootView.findViewById(R.id.map_gn_hamyang);
            ImageView map_gn_hapcheon = (ImageView)rootView.findViewById(R.id.map_gn_hapcheon);
            ImageView map_gn_jinju = (ImageView)rootView.findViewById(R.id.map_gn_jinju);
            ImageView map_gn_kimhae = (ImageView)rootView.findViewById(R.id.map_gn_kimhae);
            ImageView map_gn_millyang = (ImageView)rootView.findViewById(R.id.map_gn_millyang);
            ImageView map_gn_namhae = (ImageView)rootView.findViewById(R.id.map_gn_namhae);
            ImageView map_gn_sacheon = (ImageView)rootView.findViewById(R.id.map_gn_sacheon);
            ImageView map_gn_sancheong = (ImageView)rootView.findViewById(R.id.map_gn_sancheong);
            ImageView map_gn_tongyeong = (ImageView)rootView.findViewById(R.id.map_gn_tongyeong);
            ImageView map_gn_uiryeong = (ImageView)rootView.findViewById(R.id.map_gn_uiryeong);
            ImageView map_gn_ulsan = (ImageView)rootView.findViewById(R.id.map_gn_ulsan);
            ImageView map_gn_yangsan = (ImageView)rootView.findViewById(R.id.map_gn_yangsan);

            String name;
            name = "부산";
            paintingMap(name, map_gn_busan);
            name = "창녕";
            paintingMap(name, map_gn_changnyeong);
            name = "창원";
            paintingMap(name, map_gn_changwon);
            name = "거창";
            paintingMap(name, map_gn_geochang);
            name = "고성";
            paintingMap(name, map_gn_gosung);
            name = "거제";
            paintingMap(name, map_gn_gujae);
            name = "하동";
            paintingMap(name, map_gn_hadong);
            name = "함안";
            paintingMap(name, map_gn_haman);
            name = "함양";
            paintingMap(name, map_gn_hamyang);
            name = "합천";
            paintingMap(name, map_gn_hapcheon);
            name = "진주";
            paintingMap(name, map_gn_jinju);
            name = "김해";
            paintingMap(name, map_gn_kimhae);
            name = "밀양";
            paintingMap(name, map_gn_millyang);
            name = "남해";
            paintingMap(name, map_gn_namhae);
            name = "사천";
            paintingMap(name, map_gn_sacheon);
            name = "산청";
            paintingMap(name, map_gn_sancheong);
            name = "통영";
            paintingMap(name, map_gn_tongyeong);
            name = "의령";
            paintingMap(name, map_gn_uiryeong);
            name = "울산";
            paintingMap(name, map_gn_ulsan);
            name = "양산";
            paintingMap(name, map_gn_yangsan);
        }


        public void paintingMap(String name, ImageView image){
            Cursor cursor;

            if(activity == GANGWONDO) {
                cursor = db.rawQuery("SELECT name, color FROM gangwondo WHERE name='" + name + "';", null);
                Log.i("paintmap() --> ","activity : 강원도");
            }
            else if(activity == CHUNGCHEONGNAMDO) {
                cursor = db.rawQuery("SELECT name, color FROM chungcheongnamdo WHERE name='" + name + "';", null);
                Log.i("paintmap() --> ","activity : 충청도");
            }
            else
                cursor = db.rawQuery("SELECT name, color FROM gyeongsangnamdo WHERE name='" + name + "';", null);

            if(cursor.getCount() > 0){
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
    }

    public class SectionsPagerAdapter extends FragmentPagerAdapter {

        public SectionsPagerAdapter(FragmentManager fm) {
            super(fm);
        }

        @Override
        public Fragment getItem(int position) {
            return PlaceholderFragment.newInstance(position + 1);
        }

        @Override
        public int getCount() {
            return 3;
        }
    }
}
