package com.topwise.jnidemo;

public class AaptCall {

    static {
        System.loadLibrary("vaapt");
    }

//    public native static String get();
//    public native static String send(String mkey);
    public native static int aapt(String s1,String s2,String cmd);


}
