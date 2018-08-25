package com.example.woogyu.travelrecordsver3;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        startActivity(new Intent(this,LoadingActivity.class)); //로딩화면
    }

    //메뉴버튼 이벤트
    public void onClickMenu(View view){
        switch (view.getId()){
            case R.id.button_map:
                Intent intent = new Intent(this,MapActivity.class);
                intent.addFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP);
                startActivityForResult(intent,0);
                break;
            case R.id.button_diary:
                startActivity(new Intent(this,RecordsActivity.class));
                break;
            case R.id.button_plan:
                startActivity(new Intent(this,Schedule.class));
                break;
            case R.id.button_cost:
                startActivity(new Intent(this,Budget.class));
                break;
        }
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data){
        if(requestCode == 0){
            if(resultCode == RESULT_CANCELED){
                Log.i("Main","onActivityResult() --> RESULT OK");
            }
            else if(resultCode == RESULT_OK){
                Log.i("Main","onActivityResult() --> RESULT CANCELD");
                Intent intent = new Intent(this,MapActivity.class);
                intent.addFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP);
                startActivityForResult(intent,0);
            }
        }
    }
}
