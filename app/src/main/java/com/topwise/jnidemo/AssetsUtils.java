package com.topwise.jnidemo;

import android.content.Context;
import android.util.Log;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStream;

import static android.content.Context.MODE_PRIVATE;

public class AssetsUtils {

    static String TAG = "guohao";

    /**
     * 把 assets 目录的 fileName文件 写入到 /data/data/{包名}/files
     */
    public static String fileOpt(String fileName, Context context){

        int l = assetsFile2dataFile(fileName,context);
        Log.d(TAG,"l = " + l);

        Log.d(TAG,"getFilesDir() = " + context.getFilesDir() );
        // 输出：/data/user/0/demo.elecsign/files/MemTest.apk
        // 等价与 /data/data/demo.elecsign/files

        //Log.d(TAG,"getCacheDir() = " + getCacheDir() );
        // /data/user/0/demo.elecsign/cache

        if(l>0){
            return "/data/user/0/demo.elecsign/files/" + fileName;
        }

        return null;
    }


    // 向指定的文件中写入指定的数据
    // 创建的文件保存在/data/data/<package name>/files目录
    public static int assetsFile2dataFile(String filename,Context context){

        try {
            InputStream in = context.getAssets().open(filename);

            FileOutputStream fos = context.openFileOutput(filename, MODE_PRIVATE);//获得FileOutputStream

            //将要写入的字符串转换为byte数组
            byte[]  bytes = new byte[in.available()];
            in.read(bytes);

            fos.write(bytes);//将byte数组写入文件

            fos.close();//关闭文件输出流

            return readFileData(filename,context);

        } catch (Exception e) {
            e.printStackTrace();
        }
        return -1;
    }

    //打开指定文件，读取其数据，返回字符串对象
    public static int readFileData(String fileName,Context context){

        int len = -1;

        try{

            FileInputStream fis = context.openFileInput(fileName);

            //获取文件长度
            int lenght = fis.available();

            byte[] buffer = new byte[lenght];

            fis.read(buffer);

            len = lenght;

            //将byte数组转换成指定格式的字符串
            //result = new String(buffer, "UTF-8");

        } catch (Exception e) {
            e.printStackTrace();
        }

        return  len;
    }
}
