package com.example.woogyu.travelrecordsver3;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

public class DBHelper extends SQLiteOpenHelper {
    private static final String DATABASE_NAME = "travelrecords.db";
    private static final int DATABASE_VERSION = 1;

    public DBHelper(Context context){
        super(context,DATABASE_NAME,null,DATABASE_VERSION);
    }

    public void onCreate(SQLiteDatabase db){
        String instName;
        String instColor = "WHITE";

        //강원도 테이블
        db.execSQL("CREATE TABLE gangwondo(_id INTEGER PRIMARY KEY AUTOINCREMENT,"+"name TEXT, color TEXT);");

        //강원도 테이블 초기값
        instName = "철원";
        db.execSQL("INSERT INTO gangwondo VALUES(null,'"+instName+"','"+instColor+"');");
        instName = "춘천";
        db.execSQL("INSERT INTO gangwondo VALUES(null,'"+instName+"','"+instColor+"');");
        instName = "동해";
        db.execSQL("INSERT INTO gangwondo VALUES(null,'"+instName+"','"+instColor+"');");
        instName = "강릉";
        db.execSQL("INSERT INTO gangwondo VALUES(null,'"+instName+"','"+instColor+"');");
        instName = "홍천";
        db.execSQL("INSERT INTO gangwondo VALUES(null,'"+instName+"','"+instColor+"');");
        instName = "횡성";
        db.execSQL("INSERT INTO gangwondo VALUES(null,'"+instName+"','"+instColor+"');");
        instName = "화천";
        db.execSQL("INSERT INTO gangwondo VALUES(null,'"+instName+"','"+instColor+"');");
        instName = "인제";
        db.execSQL("INSERT INTO gangwondo VALUES(null,'"+instName+"','"+instColor+"');");
        instName = "정선";
        db.execSQL("INSERT INTO gangwondo VALUES(null,'"+instName+"','"+instColor+"');");
        instName = "고성";
        db.execSQL("INSERT INTO gangwondo VALUES(null,'"+instName+"','"+instColor+"');");
        instName = "평창";
        db.execSQL("INSERT INTO gangwondo VALUES(null,'"+instName+"','"+instColor+"');");
        instName = "삼척";
        db.execSQL("INSERT INTO gangwondo VALUES(null,'"+instName+"','"+instColor+"');");
        instName = "속초";
        db.execSQL("INSERT INTO gangwondo VALUES(null,'"+instName+"','"+instColor+"');");
        instName = "태백";
        db.execSQL("INSERT INTO gangwondo VALUES(null,'"+instName+"','"+instColor+"');");
        instName = "원주";
        db.execSQL("INSERT INTO gangwondo VALUES(null,'"+instName+"','"+instColor+"');");
        instName = "양양";
        db.execSQL("INSERT INTO gangwondo VALUES(null,'"+instName+"','"+instColor+"');");
        instName = "양구";
        db.execSQL("INSERT INTO gangwondo VALUES(null,'"+instName+"','"+instColor+"');");
        instName = "영월";
        db.execSQL("INSERT INTO gangwondo VALUES(null,'"+instName+"','"+instColor+"');");

        //충청남도 테이블
        db.execSQL("CREATE TABLE chungcheongnamdo(_id INTEGER PRIMARY KEY AUTOINCREMENT,"+"name TEXT, color TEXT);");

        //충청남도 테이블 초기값
        instName = "태안";
        db.execSQL("INSERT INTO chungcheongnamdo VALUES(null,'"+instName+"','"+instColor+"');");
        instName = "서산";
        db.execSQL("INSERT INTO chungcheongnamdo VALUES(null,'"+instName+"','"+instColor+"');");
        instName = "당진";
        db.execSQL("INSERT INTO chungcheongnamdo VALUES(null,'"+instName+"','"+instColor+"');");
        instName = "홍성";
        db.execSQL("INSERT INTO chungcheongnamdo VALUES(null,'"+instName+"','"+instColor+"');");
        instName = "예산";
        db.execSQL("INSERT INTO chungcheongnamdo VALUES(null,'"+instName+"','"+instColor+"');");
        instName = "아산";
        db.execSQL("INSERT INTO chungcheongnamdo VALUES(null,'"+instName+"','"+instColor+"');");
        instName = "보령";
        db.execSQL("INSERT INTO chungcheongnamdo VALUES(null,'"+instName+"','"+instColor+"');");
        instName = "청양";
        db.execSQL("INSERT INTO chungcheongnamdo VALUES(null,'"+instName+"','"+instColor+"');");
        instName = "천안";
        db.execSQL("INSERT INTO chungcheongnamdo VALUES(null,'"+instName+"','"+instColor+"');");
        instName = "공주";
        db.execSQL("INSERT INTO chungcheongnamdo VALUES(null,'"+instName+"','"+instColor+"');");
        instName = "연기";
        db.execSQL("INSERT INTO chungcheongnamdo VALUES(null,'"+instName+"','"+instColor+"');");
        instName = "서천";
        db.execSQL("INSERT INTO chungcheongnamdo VALUES(null,'"+instName+"','"+instColor+"');");
        instName = "부여";
        db.execSQL("INSERT INTO chungcheongnamdo VALUES(null,'"+instName+"','"+instColor+"');");
        instName = "논산";
        db.execSQL("INSERT INTO chungcheongnamdo VALUES(null,'"+instName+"','"+instColor+"');");
        instName = "계룡";
        db.execSQL("INSERT INTO chungcheongnamdo VALUES(null,'"+instName+"','"+instColor+"');");
        instName = "금산";
        db.execSQL("INSERT INTO chungcheongnamdo VALUES(null,'"+instName+"','"+instColor+"');");

        //경상남도 테이블
        db.execSQL("CREATE TABLE gyeongsangnamdo(_id INTEGER PRIMARY KEY AUTOINCREMENT,"+"name TEXT, color TEXT);");

        //경상남도 테이블 초기값
        instName = "거창";
        db.execSQL("INSERT INTO gyeongsangnamdo VALUES(null,'"+instName+"','"+instColor+"');");
        instName = "함양";
        db.execSQL("INSERT INTO gyeongsangnamdo VALUES(null,'"+instName+"','"+instColor+"');");
        instName = "합천";
        db.execSQL("INSERT INTO gyeongsangnamdo VALUES(null,'"+instName+"','"+instColor+"');");
        instName = "산청";
        db.execSQL("INSERT INTO gyeongsangnamdo VALUES(null,'"+instName+"','"+instColor+"');");
        instName = "하동";
        db.execSQL("INSERT INTO gyeongsangnamdo VALUES(null,'"+instName+"','"+instColor+"');");
        instName = "사천";
        db.execSQL("INSERT INTO gyeongsangnamdo VALUES(null,'"+instName+"','"+instColor+"');");
        instName = "진주";
        db.execSQL("INSERT INTO gyeongsangnamdo VALUES(null,'"+instName+"','"+instColor+"');");
        instName = "남해";
        db.execSQL("INSERT INTO gyeongsangnamdo VALUES(null,'"+instName+"','"+instColor+"');");
        instName = "의령";
        db.execSQL("INSERT INTO gyeongsangnamdo VALUES(null,'"+instName+"','"+instColor+"');");
        instName = "창녕";
        db.execSQL("INSERT INTO gyeongsangnamdo VALUES(null,'"+instName+"','"+instColor+"');");
        instName = "고성";
        db.execSQL("INSERT INTO gyeongsangnamdo VALUES(null,'"+instName+"','"+instColor+"');");
        instName = "함안";
        db.execSQL("INSERT INTO gyeongsangnamdo VALUES(null,'"+instName+"','"+instColor+"');");
        instName = "창원";
        db.execSQL("INSERT INTO gyeongsangnamdo VALUES(null,'"+instName+"','"+instColor+"');");
        instName = "밀양";
        db.execSQL("INSERT INTO gyeongsangnamdo VALUES(null,'"+instName+"','"+instColor+"');");
        instName = "통영";
        db.execSQL("INSERT INTO gyeongsangnamdo VALUES(null,'"+instName+"','"+instColor+"');");
        instName = "거제";
        db.execSQL("INSERT INTO gyeongsangnamdo VALUES(null,'"+instName+"','"+instColor+"');");
        instName = "김해";
        db.execSQL("INSERT INTO gyeongsangnamdo VALUES(null,'"+instName+"','"+instColor+"');");
        instName = "양산";
        db.execSQL("INSERT INTO gyeongsangnamdo VALUES(null,'"+instName+"','"+instColor+"');");
        instName = "부산";
        db.execSQL("INSERT INTO gyeongsangnamdo VALUES(null,'"+instName+"','"+instColor+"');");
        instName = "울산";
        db.execSQL("INSERT INTO gyeongsangnamdo VALUES(null,'"+instName+"','"+instColor+"');");

        //지역테이블
        db.execSQL("CREATE TABLE location(_id INTEGER PRIMARY KEY AUTOINCREMENT,"+"loc TEXT);");

        //지역테이블 초기값
        instName = "강원도";
        db.execSQL("INSERT INTO location VALUES(null,'"+instName+"');");
        instName = "충청남도";
        db.execSQL("INSERT INTO location VALUES(null,'"+instName+"');");
        instName = "경상남도";
        db.execSQL("INSERT INTO location VALUES(null,'"+instName+"');");

        //기록 테이블
        db.execSQL("CREATE TABLE records(_id INTEGER PRIMARY KEY AUTOINCREMENT,"+"title TEXT, memo TEXT, uri TEXT, time TEXT, loc TEXT, date TEXT, spot TEXT);");

        //추가부분
        db.execSQL("CREATE TABLE detailSchedule ( _id INTEGER PRIMARY KEY AUTOINCREMENT, " +
                "schid NUMBER, date TEXT, time TEXT, dest TEXT, room TEXT, memo TEXT, succ Text);");

        db.execSQL("CREATE TABLE budget ( _id INTEGER PRIMARY KEY AUTOINCREMENT, " +
                "bdgtid NUMBER, item TEXT, cost NUMBER);");

        db.execSQL("CREATE TABLE tbudget ( _id INTEGER PRIMARY KEY AUTOINCREMENT, " +
                "bdgtid NUMBER, title TEXT, tcost NUMBER);");
    }

    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion){
        db.execSQL("DROP TABLE IF EXISTS gangwondo");
        db.execSQL("DROP TABLE IF EXISTS chungcheongnamdo");
        db.execSQL("DROP TABLE IF EXISTS gyeongsangnamdo");
        db.execSQL("DROP TABLE IF EXISTS location");
        db.execSQL("DROP TABLE IF EXISTS records");
        onCreate(db);
    }
}
