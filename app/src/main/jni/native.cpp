//
// Created by topwise on 18-9-27.
//
#include <com_topwise_jnidemo_MyJni.h>
#include <android/log.h>
#include <string.h>
#include <stdlib.h>

// 为了打log
#define LOG_TAG "guohao"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

char Header[1024];
//char* file[10]={"123","456"};
char file[2][10]={0};

char* jstringToChar(JNIEnv* env, jstring jstr)
{
    char* rtn = NULL;
    jclass clsstring = env->FindClass("java/lang/String");
    jstring strencode = env->NewStringUTF("utf-8");
    jmethodID mid = env->GetMethodID(clsstring, "getBytes", "(Ljava/lang/String;)[B");
    jbyteArray barr= (jbyteArray)env->CallObjectMethod(jstr, mid, strencode);
    env->DeleteLocalRef( strencode);
    jsize alen = env->GetArrayLength(barr);
    jbyte* ba = env->GetByteArrayElements(barr, JNI_FALSE);
    if (alen > 0){
        rtn = (char*)malloc(alen + 1);
        memcpy(rtn, ba, alen);
        rtn[alen] = 0;
    }
    env->ReleaseByteArrayElements(barr, ba, 0);
    return rtn;
}

JNIEXPORT jstring JNICALL Java_com_topwise_jnidemo_MyJni_get
  (JNIEnv *env, jobject jo){

       LOGI("here is native get!");
       //LOGI("%s",file[0]);
       //LOGI("%s",file[1]);

       return env->NewStringUTF("hello java,I'm native.cpp get");
  };

JNIEXPORT jstring JNICALL Java_com_topwise_jnidemo_MyJni_send
  (JNIEnv *env, jobject jo, jstring js){
        LOGI("here is native send! the param = %s", jstringToChar(env,js));
        strcat(Header,"I'm native.cpp send.\n");
        strcat(Header,"The param is \n");
        strcat(Header,jstringToChar(env,js));

        strcpy(file[0],jstringToChar(env,js));
        LOGI("%s",file[0]);

        return env->NewStringUTF(Header);
  }

