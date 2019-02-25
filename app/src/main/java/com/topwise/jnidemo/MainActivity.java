package com.topwise.jnidemo;

import android.os.Bundle;
import android.util.Log;
import android.view.View;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.IllegalFormatCodePointException;

public class MainActivity extends BaseTestActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        setContentView(R.layout.activity_main);
        super.onCreate(savedInstanceState);

    }

    public void test_1(View c){
        Log.d("guohao",MyJni.get());
        showMessage(MyJni.send("just do it"));
    }

    // aapt remove
    // 输入名字不够方便
    public void test_2(View c){
        String s1 = "/data/user/0/com.topwise.jnidemo/files/sougou.apk";
        String s2 = "resources.arsc";
        showMessage("" + AaptCall.aapt(s1,s2,"r"));//传空报错
    }

    // aapt list
    public void test_3(View c){
        String s1 = "/data/user/0/com.topwise.jnidemo/files/sougou.apk";
        String s2 = "bbb"; // 随便写
        showMessage("" + AaptCall.aapt(s1,s2,"l"));
    }

    // aapt version
    public void test_4(View c){
        String s1 = "aaa";
        String s2 = "bbb";
        showMessage("" + AaptCall.aapt(s1,s2,"v"));
    }

    // 有空独立成类
    public void test_gen_apk(View c){
        AssetsUtils.fileOpt("sougou.apk",this);//生成一个文件到本地先
    }

    MessageDigest messageDigest;
    public void test_md5(View v){
        try {
            messageDigest = MessageDigest.getInstance("MD5");
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        }

        // 输入的字符串转换成字节数组
        String input = "restime=1539221277";
        showMessage("原始数据：\n" + input);
        String key = "bfyj2IjOHLCuxBpSfDRYwjbrW";
        showMessage("key：\n" + key);
        String wait_sign = input + key;
        showMessage("组串数据：\n" + wait_sign);

        byte[] inputByteArray = wait_sign.getBytes();


        // inputByteArray是输入字符串转换得到的字节数组

        messageDigest.update(inputByteArray);


        // 转换并返回结果，也是字节数组，包含16个元素
        byte[] resultByteArray = messageDigest.digest();


        // 字符数组转换成字符串返回
        String res =  byteArrayToHex(resultByteArray);

        showMessage(res.toLowerCase());
        //showMessage(bytesToString(resultByteArray));

    }

    //下面这个函数用于将字节数组换成成16进制的字符串
    public static String byteArrayToHex(byte[] byteArray) {

        // 首先初始化一个字符数组，用来存放每个16进制字符

        char[] hexDigits = {'0','1','2','3','4','5','6','7','8','9', 'A','B','C','D','E','F' };



        // new一个字符数组，这个就是用来组成结果字符串的（解释一下：一个byte是八位二进制，也就是2位十六进制字符（2的8次方等于16的2次方））

        char[] resultCharArray =new char[byteArray.length * 2];



        // 遍历字节数组，通过位运算（位运算效率高），转换成字符放到字符数组中去

        int index = 0;

        for (byte b : byteArray) {

            resultCharArray[index++] = hexDigits[b>>> 4 & 0xf];

            resultCharArray[index++] = hexDigits[b& 0xf];

        }



        // 字符数组组合成字符串返回

        return new String(resultCharArray);
    }


    public static String bytesToString(byte[] srcBytes) {
        if (srcBytes == null) {
            return null;
        }
        StringBuilder builder = new StringBuilder();
        //String 不可变，还是不要使用 new 创建 String 对象吧
        try {
            for (byte currentByte : srcBytes) {
                //builder.append(String.format("%c", currentByte));
                builder.append((char)currentByte);
            }
        } catch (IllegalFormatCodePointException e) {
        }
        return builder.toString();
    }


}
