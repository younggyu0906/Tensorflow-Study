package com.example.ygkim.pizzaorder;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.RadioButton;
import android.widget.CheckBox;
import android.widget.TextView;


public class MainActivity extends AppCompatActivity {
    private int m_Total = 0;        // 총 가격을 나타내는 멤버변수
    private int m_Dough = 0;        // 도우 가격을 나타내는 멤버변수
    private int m_Topping = 0;      // 토핑 가격을 나타내는 멤버변수

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public void onDoughClick(View view) {       // 도우 선택을 위한 라디오버튼 이벤트 처리 함수
        boolean checked = ((RadioButton) view).isChecked();
        TextView text = (TextView)findViewById(R.id.textView4); // TextView 객체 선언
        switch(view.getId()) {          // 도우는 한 개만 선택 가능하므로 선택되었을 때 멤버변수 m_Dough를 해당 가격으로 초기화
            case R.id.radioButton:
                if(checked)
                    m_Dough = 10000;
                break;
            case R.id.radioButton2:
                if(checked)
                    m_Dough = 15000;
                break;
            case R.id.radioButton3:
                if(checked)
                    m_Dough = 13000;
                break;
        }
        text.setText(Integer.toString(m_Total = m_Dough + m_Topping));  // 총 가격은 도우가격 + 토핑가격, int형 변수인 m_Total을 String으로 형변환하여 TextView 설정
    }

    public void onToppingClick(View view) {     // 토핑 선택을 위한 체크박스 이벤트 처리 함수
        boolean checked = ((CheckBox) view).isChecked();
        TextView text = (TextView)findViewById(R.id.textView4); // TextView 객체 선언
        switch(view.getId()) {      // 토핑은 선택되거나 해제되었을 때 해당 가격을 가감산 해야 하므로 멤버변수 m_Topping에 += or -= 연산자 사용
            case R.id.checkBox:
                if(checked)
                    m_Topping += 3000;
                else
                    m_Topping -= 3000;
                break;
            case R.id.checkBox2:
                if(checked)
                    m_Topping += 2000;
                else
                    m_Topping -= 2000;
                break;
            case R.id.checkBox3:
                if(checked)
                    m_Topping += 4000;
                else
                    m_Topping -= 4000;
                    break;
        }
        text.setText(Integer.toString(m_Total = m_Dough + m_Topping));  // 총 가격은 도우가격 + 토핑가격, int형 변수인 m_Total을 String으로 형변환하여 TextView 설정
    }
}
