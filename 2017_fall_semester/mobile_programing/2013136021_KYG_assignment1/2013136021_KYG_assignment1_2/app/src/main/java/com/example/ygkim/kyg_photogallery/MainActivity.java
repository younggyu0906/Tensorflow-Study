package com.example.ygkim.kyg_photogallery;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.ImageView;
import android.view.View;

public class MainActivity extends AppCompatActivity {
    private ImageView mainImage, thImage1, thImage2, thImage3, thImage4;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // 이미지 뷰 인스턴스 초기화
        mainImage = (ImageView)findViewById(R.id.image01);
        thImage1 = (ImageView)findViewById(R.id.thumbnail01);
        thImage2 = (ImageView)findViewById(R.id.thumbnail02);
        thImage3 = (ImageView)findViewById(R.id.thumbnail03);
        thImage4 = (ImageView)findViewById(R.id.thumbnail04);

        // 클릭 이벤트 리스너 등록
        thImage1.setOnClickListener(new MyListener());
        thImage2.setOnClickListener(new MyListener());
        thImage3.setOnClickListener(new MyListener());
        thImage4.setOnClickListener(new MyListener());
    }

    // 리스너 내부 클래스
    class MyListener implements View.OnClickListener {
        // onClick() 함수 구현
        public void onClick(View view) {
            switch (view.getId()) {     // 뷰가 클릭되었을 때마다 각 뷰에 따라
                // 메인 이미지 변경
                case R.id.thumbnail01:
                        mainImage.setImageResource(R.drawable.chicken);
                        break;
                case R.id.thumbnail02:
                        mainImage.setImageResource(R.drawable.fried_shrimp);
                        break;
                case R.id.thumbnail03:
                        mainImage.setImageResource(R.drawable.pork_cutlet);
                        break;
                case R.id.thumbnail04:
                        mainImage.setImageResource(R.drawable.tangsuyuk);
                        break;
            }
        }
    }
}
