package com.example.ygkim.a2013136021_kyg_assignment2;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.content.Intent;
import android.view.View;
import android.widget.EditText;
import android.widget.Button;

public class Add_bookmark extends AppCompatActivity {
    EditText nameEdit;
    EditText urlEdit;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_add_bookmark);

        nameEdit = (EditText)findViewById(R.id.nameEdit);
        urlEdit = (EditText)findViewById(R.id.urlEdit);

        Button addBtn = (Button)findViewById(R.id.addButton);
        addBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent();
                intent.putExtra("NAME_TEXT", nameEdit.getText().toString());
                intent.putExtra("URL_TEXT", urlEdit.getText().toString());
                setResult(RESULT_OK, intent);
                finish();
            }
        });
    }
}
