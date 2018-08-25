package com.example.woogyu.travelrecordsver3;

import android.Manifest;
import android.app.AlertDialog;
import android.app.DatePickerDialog;
import android.app.Dialog;
import android.app.DialogFragment;
import android.content.ComponentName;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.SharedPreferences;
import android.content.pm.PackageManager;
import android.content.pm.ResolveInfo;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteException;
import android.graphics.Bitmap;
import android.graphics.Color;
import android.graphics.drawable.ColorDrawable;
import android.media.MediaScannerConnection;
import android.net.Uri;
import android.os.Build;
import android.os.Environment;
import android.provider.MediaStore;
import android.support.v4.app.ActivityCompat;
import android.support.v4.content.ContextCompat;
import android.support.v4.content.FileProvider;
import android.support.v7.app.ActionBar;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.support.v7.widget.Toolbar;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Adapter;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.DatePicker;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;

import java.io.File;
import java.io.IOException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.Date;
import java.util.List;

public class RecordsAddActivity extends AppCompatActivity implements View.OnClickListener, DialogInterface.OnClickListener {
    //사진선택이미지
    private ImageView imgMain;

    //request코드 설정
    private static final int PICK_FROM_CAMERA = 1;
    private static final int PICK_FROM_ALBUM = 2;
    private static final int CROP_FROM_CAMERA = 3;

    //수정인지 추가인지 확인
    private static final int ADD = 1;
    private static final int CHANGE = 2;

    private Uri photoUri;
    private String[] permissions = {Manifest.permission.READ_EXTERNAL_STORAGE,
            Manifest.permission.WRITE_EXTERNAL_STORAGE,
            Manifest.permission.CAMERA};
    private static final int MULTIPLE_PERMISSIONS = 101;

    private String mCurrentPhotoPath;
    //DB객체
    DBHelper helper;
    SQLiteDatabase db;

    //저장시각을 저장할 객체
    long mNow;
    Date mDate;
    SimpleDateFormat mFormat = new SimpleDateFormat("yyyy-MM-dd hh:mm:ss");

    int select;
    String selectUri;

    EditText title;
    EditText memo;
    EditText loc;
    EditText date;
    EditText spot;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_records_add);

        select = getIntent().getIntExtra("SELECT",0);
        Log.i("test-->","SELECT : "+Integer.toString(select));

        //액션바생성 및 설정
        Toolbar toolBar;
        if(select == ADD) {
            toolBar = (Toolbar) findViewById(R.id.toolbar2);
            toolBar.setVisibility(View.GONE);
            toolBar = (Toolbar) findViewById(R.id.toolbar);
            setSupportActionBar(toolBar);
        }
        else if(select == CHANGE) {
            toolBar = (Toolbar) findViewById(R.id.toolbar2);
            setSupportActionBar(toolBar);
        }

        ActionBar actionBar = getSupportActionBar();
        actionBar.setBackgroundDrawable(new ColorDrawable(0xFFFF4081));

        //디비 생성 및 불러오기
        helper = new DBHelper(this);
        try {
            db = helper.getWritableDatabase();
        }catch (SQLiteException ex){
            db = helper.getReadableDatabase();
        }

        //권한체크
        checkPermissions();
        imgMain = (ImageView)findViewById(R.id.image_records);
        title = (EditText)findViewById(R.id.edit_memo_title);
        memo = (EditText)findViewById(R.id.edit_memo);
        loc = (EditText)findViewById(R.id.edit_loc);
        date = (EditText)findViewById(R.id.edit_date);
        spot = (EditText)findViewById(R.id.edit_spot);

        if(select == CHANGE){
            selectUri = getIntent().getStringExtra("URI");
            settings(selectUri);
        }

        ImageView imageDate = (ImageView)findViewById(R.id.memo_date);
        imageDate.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v) {
                TextView textView = (TextView)findViewById(R.id.edit_date);

                DatePickerFragment dpf = new DatePickerFragment();
                dpf.setEditText(textView);
                dpf.show(getFragmentManager(), "datePicker");
            }
        });

        ImageView imageAdd = (ImageView)findViewById(R.id.memo_addbox);
        imageAdd.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v) {
                DialogSelectOption();
            }
        });
    }

    public void settings(String uri){
        photoUri = Uri.parse(uri);
        imgMain.setImageURI(null);
        imgMain.setImageURI(photoUri);

        Cursor cursor = db.rawQuery("SELECT title, memo, loc, date, spot FROM records WHERE uri='"+uri+"';",null);

        cursor.moveToFirst();
        title.setText(cursor.getString(0));
        memo.setText(cursor.getString(1));
        loc.setText(cursor.getString(2));
        date.setText(cursor.getString(3));
        spot.setText(cursor.getString(4));
    }

    @Override
    public void onClick(View v) {
        if(v.getId() == R.id.image_records) {
            DialogInterface.OnClickListener cameraListener = new DialogInterface.OnClickListener() {
                @Override
                public void onClick(DialogInterface dialog, int which) {
                    doTakePhotoAction();
                }
            };

            DialogInterface.OnClickListener albumListener = new DialogInterface.OnClickListener() {
                @Override
                public void onClick(DialogInterface dialog, int which) {
                    doTakeAlbumAction();
                }
            };

            DialogInterface.OnClickListener cancelListener = new DialogInterface.OnClickListener() {
                @Override
                public void onClick(DialogInterface dialog, int which) {
                    dialog.dismiss();
                }
            };

            new AlertDialog.Builder(this)
                    .setTitle("기록할 이미지 선택")
                    .setPositiveButton("사진촬영", cameraListener)
                    .setNeutralButton("앨범선택", albumListener)
                    .setNegativeButton("취소", cancelListener)
                    .show();
        }
    }

    private boolean checkPermissions() {
        int result;
        List<String> permissionList = new ArrayList<>();
        for (String pm : permissions) {
            result = ContextCompat.checkSelfPermission(this, pm);
            if (result != PackageManager.PERMISSION_GRANTED) {
                permissionList.add(pm);
            }
        }
        if (!permissionList.isEmpty()) {
            ActivityCompat.requestPermissions(this, permissionList.toArray(new String[permissionList.size()]), MULTIPLE_PERMISSIONS);
            return false;
        }
        return true;
    }

    private void doTakePhotoAction() {
        Intent intent = new Intent(MediaStore.ACTION_IMAGE_CAPTURE);
        File photoFile = null;
        try {
            photoFile = createImageFile();
        } catch (IOException e) {
            Toast.makeText(RecordsAddActivity.this, "이미지 처리 오류! 다시 시도해주세요.", Toast.LENGTH_SHORT).show();
            finish();
            e.printStackTrace();
        }
        if (photoFile != null) {
            if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.N) {//sdk 24 이상
                photoUri = FileProvider.getUriForFile(getApplicationContext(),
                        BuildConfig.APPLICATION_ID + ".provider", photoFile);
            } else {//sdk 23 이하, 7.0 미만
                photoUri = Uri.fromFile(photoFile);
            }
            intent.putExtra(MediaStore.EXTRA_OUTPUT, photoUri);
            startActivityForResult(intent, PICK_FROM_CAMERA);
        }
    }

    private File createImageFile() throws IOException {
        String timeStamp = new SimpleDateFormat("HHmmss").format(new Date());
        String imageFileName = "records_" + timeStamp + "_";
        File storageDir = new File(Environment.getExternalStorageDirectory() + "/Trevelrecords/");
        if (!storageDir.exists()) {
            storageDir.mkdirs();
        }
        File image = File.createTempFile(imageFileName, ".jpg", storageDir);
        mCurrentPhotoPath = "file:" + image.getAbsolutePath();
        return image;
    }

    private void doTakeAlbumAction() {
        Intent intent = new Intent(Intent.ACTION_PICK);
        intent.setType(MediaStore.Images.Media.CONTENT_TYPE);
        startActivityForResult(intent, PICK_FROM_ALBUM);
    }


    @Override
    public void onRequestPermissionsResult(int requestCode, String permissions[], int[] grantResults) {
        switch (requestCode) {
            case MULTIPLE_PERMISSIONS: {
                if (grantResults.length > 0) {
                    for (int i = 0; i < permissions.length; i++) {
                        if (permissions[i].equals(this.permissions[0])) {
                            if (grantResults[i] != PackageManager.PERMISSION_GRANTED) {
                                showNoPermissionToastAndFinish();
                            }
                        } else if (permissions[i].equals(this.permissions[1])) {
                            if (grantResults[i] != PackageManager.PERMISSION_GRANTED) {
                                showNoPermissionToastAndFinish();

                            }
                        } else if (permissions[i].equals(this.permissions[2])) {
                            if (grantResults[i] != PackageManager.PERMISSION_GRANTED) {
                                showNoPermissionToastAndFinish();

                            }
                        }
                    }
                } else {
                    showNoPermissionToastAndFinish();
                }
                return;
            }
        }
    }

    private void showNoPermissionToastAndFinish() {
        Toast.makeText(this, "권한 요청에 동의 해주셔야 이용 가능합니다.", Toast.LENGTH_SHORT).show();
        finish();
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        if (resultCode != RESULT_OK) {
            return;
        }
        if (requestCode == PICK_FROM_ALBUM) {
            if (data == null) {
                return;
            }
            photoUri = data.getData();
            cropImage();
        } else if (requestCode == PICK_FROM_CAMERA) {
            cropImage();
            // 갤러리에 나타나게
            MediaScannerConnection.scanFile(RecordsAddActivity.this,
                    new String[]{photoUri.getPath()}, null,
                    new MediaScannerConnection.OnScanCompletedListener() {
                        public void onScanCompleted(String path, Uri uri) {
                        }
                    });
        } else if (requestCode == CROP_FROM_CAMERA) {
            imgMain.setImageURI(null);
            imgMain.setImageURI(photoUri);
        }
    }

    //Android N crop image
    public void cropImage() {
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.N) {
            this.grantUriPermission("com.android.camera", photoUri,
                    Intent.FLAG_GRANT_WRITE_URI_PERMISSION | Intent.FLAG_GRANT_READ_URI_PERMISSION);
        }
        Intent intent = new Intent("com.android.camera.action.CROP");
        intent.setDataAndType(photoUri, "image/*");

        List<ResolveInfo> list = getPackageManager().queryIntentActivities(intent, 0);
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.N) {
            grantUriPermission(list.get(0).activityInfo.packageName, photoUri,
                    Intent.FLAG_GRANT_WRITE_URI_PERMISSION | Intent.FLAG_GRANT_READ_URI_PERMISSION);
        }
        int size = list.size();
        if (size == 0) {
            Toast.makeText(this, "취소", Toast.LENGTH_SHORT).show();
            return;
        } else {
            Toast.makeText(this, "용량이 큰 사진의 경우 시간이 오래 걸릴 수 있습니다.", Toast.LENGTH_SHORT).show();

            if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.N) {
                intent.addFlags(Intent.FLAG_GRANT_READ_URI_PERMISSION);
                intent.addFlags(Intent.FLAG_GRANT_WRITE_URI_PERMISSION);
            }
            intent.putExtra("crop", "true");
            intent.putExtra("aspectX", 4);
            intent.putExtra("aspectY", 3);
            intent.putExtra("scale", true);
            File croppedFileName = null;
            try {
                croppedFileName = createImageFile();
            } catch (IOException e) {
                e.printStackTrace();
            }

            File folder = new File(Environment.getExternalStorageDirectory() + "/Trevelrecords/");
            File tempFile = new File(folder.toString(), croppedFileName.getName());


            if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.N) {//sdk 24 이상, 누가(7.0)
                photoUri = FileProvider.getUriForFile(getApplicationContext(),
                        BuildConfig.APPLICATION_ID + ".provider", tempFile);
            } else {//sdk 23 이하, 7.0 미만
                photoUri = Uri.fromFile(tempFile);
            }

            if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.N) {
                intent.addFlags(Intent.FLAG_GRANT_READ_URI_PERMISSION);
                intent.addFlags(Intent.FLAG_GRANT_WRITE_URI_PERMISSION);
            }

            intent.putExtra("return-data", false);
            intent.putExtra(MediaStore.EXTRA_OUTPUT, photoUri);
            intent.putExtra("outputFormat", Bitmap.CompressFormat.JPEG.toString());

            Intent i = new Intent(intent);
            ResolveInfo res = list.get(0);
            if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.N) {
                i.addFlags(Intent.FLAG_GRANT_READ_URI_PERMISSION);
                i.addFlags(Intent.FLAG_GRANT_WRITE_URI_PERMISSION);

                grantUriPermission(res.activityInfo.packageName, photoUri,
                        Intent.FLAG_GRANT_WRITE_URI_PERMISSION | Intent.FLAG_GRANT_READ_URI_PERMISSION);
            }
            i.setComponent(new ComponentName(res.activityInfo.packageName, res.activityInfo.name));
            startActivityForResult(i, CROP_FROM_CAMERA);
        }
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.menu_record_add, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        int id = item.getItemId();

        if(id == R.id.action_save) {
            try {
                String instTitle = title.getText().toString();
                String instMemo = memo.getText().toString();
                String instUri = photoUri.getPath();
                String instTime = getTime();
                String instLoc = loc.getText().toString();
                String instDate = date.getText().toString();
                String instSpot = spot.getText().toString();

                if(select == CHANGE)
                    db.execSQL("UPDATE records SET title='"+instTitle+"',memo='"+instMemo+"',uri='"+instUri+"',time='"+instTime+"',loc='"+instLoc+"',date='"+instDate+"',spot='"+instSpot+"'WHERE uri='"+selectUri+"';");
                else if(select == ADD)
                    db.execSQL("INSERT INTO records VALUES(null,'"+instTitle+"','"+instMemo+"','"+instUri+"','"+instTime+"','"+instLoc+"','"+instDate+"','"+instSpot+"');");

                Intent intent = new Intent();
                intent.putExtra("TIME",instTime);
                intent.putExtra("URI",instUri);
                setResult(RESULT_CANCELED,intent);
                finish();
                return true;
            }catch (NullPointerException e) {
                new AlertDialog.Builder(this)
                        .setTitle("사진을 선택해주세요")
                        .setIcon(R.drawable.ic_error_black_24dp)
                        .setPositiveButton("확인", new DialogInterface.OnClickListener() {
                            @Override
                            public void onClick(DialogInterface dialogInterface, int i) {
                                DialogInterface.OnClickListener cameraListener = new DialogInterface.OnClickListener() {
                                    @Override
                                    public void onClick(DialogInterface dialog, int which) {
                                        doTakePhotoAction();
                                    }
                                };
                                DialogInterface.OnClickListener albumListener = new DialogInterface.OnClickListener() {
                                    @Override
                                    public void onClick(DialogInterface dialog, int which) {
                                        doTakeAlbumAction();
                                    }
                                };
                                DialogInterface.OnClickListener cancelListener = new DialogInterface.OnClickListener() {
                                    @Override
                                    public void onClick(DialogInterface dialog, int which) {
                                        dialog.dismiss();
                                    }
                                };
                                new AlertDialog.Builder(RecordsAddActivity.this)
                                        .setTitle("업로드할 이미지 선택")
                                        .setPositiveButton("사진촬영", cameraListener)
                                        .setNeutralButton("앨범선택", albumListener)
                                        .setNegativeButton("취소", cancelListener)
                                        .show();
                            }
                        })
                        .setNegativeButton("취소", new DialogInterface.OnClickListener() {
                            @Override
                            public void onClick(DialogInterface dialog, int i) {
                                dialog.dismiss();
                            }
                        })
                        .show();
            }
        }else if(id == R.id.action_exit) {
            setResult(RESULT_OK);
            finish();
        }else if (id == R.id.action_remove){
            new AlertDialog.Builder(this)
                    .setTitle("초기화 하시겠습니까?")
                    .setIcon(R.drawable.ic_info_black_24dp)
                    .setPositiveButton("확인", new DialogInterface.OnClickListener() {
                        @Override
                        public void onClick(DialogInterface dialogInterface, int i) {
                            Toast.makeText(getApplicationContext(),"초기화",Toast.LENGTH_SHORT);
                            title.setText("");
                            memo.setText("");
                            loc.setText("");
                            date.setText("");
                            spot.setText("");
                            imgMain.setImageResource(R.drawable.add_image);
                            photoUri = null;
                        }
                    })
                    .setNegativeButton("취소", new DialogInterface.OnClickListener() {
                        @Override
                        public void onClick(DialogInterface dialogInterface, int i) {
                            dialogInterface.dismiss();
                        }
                    })
                    .show();
        }
        return super.onOptionsItemSelected(item);
    }

    private String getTime(){
        mNow = System.currentTimeMillis();
        mDate = new Date(mNow);
        return mFormat.format(mDate);
    }

    public static class DatePickerFragment extends DialogFragment implements DatePickerDialog.OnDateSetListener {
        TextView mT;

        public void setEditText(TextView et) {
            mT = et;
        }

        @Override
        public Dialog onCreateDialog(Bundle savedInstanceState) {
            Calendar cal = Calendar.getInstance();
            return new DatePickerDialog(getActivity(), this, cal.get(Calendar.YEAR), cal.get(Calendar.MONTH), cal.get(Calendar.DATE));
        }

        @Override
        public void onDateSet(DatePicker view, int year, int monthOfYear, int dayOfMonth) {
            mT.setText(year + "/" + (monthOfYear + 1) + "/" + dayOfMonth);
        }
    }

    String items[];
    private void DialogSelectOption() {
        Cursor cursor = db.rawQuery("SELECT loc FROM location;",null);
        int length = cursor.getCount();

        cursor.moveToFirst();
        items = new String[length];
        for (int i = 0; i < length; i++){
            items[i] = cursor.getString(0);
            cursor.moveToNext();
        }

        AlertDialog.Builder ab = new AlertDialog.Builder(RecordsAddActivity.this);
        ab.setTitle("지역선택");
        ab.setSingleChoiceItems(items, 0, this)
                .setPositiveButton("확인",this)
                .setNegativeButton("취소",this);
        ab.show();
    }

    public String locName;
    int position;
    @Override
    public void onClick(final DialogInterface dialog, int whichButton) {
        if(whichButton >= 0)
            position = whichButton;
        else if(whichButton == -1){
            locName = items[position];
            Cursor cursor;
            final String names[];
            int length;
            switch (locName){
                case "강원도" :
                    cursor = db.rawQuery("SELECT name FROM gangwondo;",null);
                    length = cursor.getCount();

                    cursor.moveToFirst();
                    names = new String[length];
                    for (int i = 0; i < length; i++){
                        names[i] = cursor.getString(0);
                        cursor.moveToNext();
                    }
                    break;
                case "충청남도" :
                    cursor = db.rawQuery("SELECT name FROM chungcheongnamdo;",null);
                    length = cursor.getCount();

                    cursor.moveToFirst();
                    names = new String[length];
                    for (int i = 0; i < length; i++){
                        names[i] = cursor.getString(0);
                        cursor.moveToNext();
                    }
                    break;
                case "경상남도" :
                    cursor = db.rawQuery("SELECT name FROM gyeongsangnamdo;",null);
                    length = cursor.getCount();

                    cursor.moveToFirst();
                    names = new String[length];
                    for (int i = 0; i < length; i++){
                        names[i] = cursor.getString(0);
                        cursor.moveToNext();
                    }
                    break;
                default:
                    names = new String[1];
            }

            AlertDialog.Builder ab = new AlertDialog.Builder(RecordsAddActivity.this);
            ab.setTitle("지역선택");
            ab.setSingleChoiceItems(names, 0, new DialogInterface.OnClickListener() {
                @Override
                public void onClick(DialogInterface dialogInterface, int which) {
                    EditText editLoc = (EditText)findViewById(R.id.edit_loc);
                    editLoc.setText(locName+" "+names[which]);

                    dialogInterface.dismiss();
                }
            });
            ab.show();
        }
        else
            dialog.dismiss();
    }
}
