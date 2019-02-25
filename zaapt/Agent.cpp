//
// Created by topwise on 18-9-27.
//
#include "jni.h"
#include "Main.h"
#include "Bundle.h"

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
    jclass clsstring = (*env)->FindClass(env,"java/lang/String");
    jstring strencode = (*env)->NewStringUTF(env,"utf-8");
    jmethodID mid = (*env)->GetMethodID(env,clsstring, "getBytes", "(Ljava/lang/String;)[B");
    jbyteArray barr= (jbyteArray)(*env)->CallObjectMethod(env,jstr, mid, strencode);
    (*env)->DeleteLocalRef(env,strencode);
    jsize alen = (*env)->GetArrayLength(env,barr);
    jbyte* ba = (*env)->GetByteArrayElements(env,barr, 0);
    if (alen > 0){
        rtn = (char*)malloc(alen + 1);
        memcpy(rtn, ba, alen);
        rtn[alen] = 0;
    }
    (*env)->ReleaseByteArrayElements(env,barr, ba, 0);
    return rtn;
}

JNIEXPORT jstring JNICALL Java_com_topwise_jnidemo_MyJni_get
  (JNIEnv *env, jobject jo){

       LOGI("here is native get!");
       //LOGI("%s",file[0]);
       //LOGI("%s",file[1]);

       return (*env)->NewStringUTF(env,"hello java,I'm native.cpp get");
  };

JNIEXPORT jstring JNICALL Java_com_topwise_jnidemo_MyJni_send
  (JNIEnv *env, jobject jo, jstring js){
        LOGI("here is native send! the param = %s", jstringToChar(env,js));
        strcat(Header,"I'm native.cpp send.\n");
        strcat(Header,"The param is \n");
        strcat(Header,jstringToChar(env,js));

        strcpy(file[0],jstringToChar(env,js));
        LOGI("%s",file[0]);

        return (*env)->NewStringUTF(env,Header);
  }

JNIEXPORT jint JNICALL Java_com_topwise_jnidemo_AaptCall_aapt
  (JNIEnv *env, jobject jo, jstring js1, jstring js2,jstring js3){

	//char* const argv[]={"a.apk","b.jpg"};
	//LOGI("argv[0] = %s",argv[0]);
	//LOGI("argv[1] = %s",argv[1]);

	//char argv[2][10]={0};
	//strcpy(argv[0],jstringToChar(env,js1));
	//strcpy(argv[1],jstringToChar(env,js2));
	//LOGI("test argv[0] = %s",argv[0]);
	//LOGI("test argv[1] = %s",argv[1]);
	// bundle.setFileSpec(argv, 2);遇到该问题
	// error: cannot initialize a parameter of type 'char *const *' with an lvalue of type 'char [2][10]'
	// lvalue 表示可赋值的，也就是说，argv 是可赋值的。

	int size = 2;
	int clm = 100;
	char* p[size]; // p 是已经赋值了，不可再赋值。
	
	for(int i=0;i<2;i++)
	{
		p[i]=new char[clm];
	}

	strcpy(p[0],jstringToChar(env,js1));
	strcpy(p[1],jstringToChar(env,js2));

	LOGI("guohao p[0] = %s",p[0]);
	LOGI("guohao p[1] = %s",p[1]);

	Bundle bundle;
	/* default to compression */
	bundle.setCompressionMethod(ZipEntry::kCompressDeflated);
	
	int res = -1;
	char cmd[2] = {0}; 
	strcpy(cmd,jstringToChar(env,js3));
	LOGI("guohao cmd = %s",cmd);

	if(cmd[0] == 'r'){
		LOGI("guohao exec doRemove ");
		// char* argv[] ,int argc
		bundle.setFileSpec(p, 2);// 2 是指参数个数
		bundle.setCommand(kCommandRemove);
		res = doRemove(&bundle);	
	}else if(cmd[0] == 'v'){
		LOGI("guohao exec doVersion ");
		bundle.setCommand(kCommandVersion);
		res = doVersion(&bundle);
	}else if(cmd[0] == 'l'){
		LOGI("guohao exec doList ");
		bundle.setFileSpec(p, 1);// 1 是指参数个数
		bundle.setCommand(kCommandList);
		res = doList(&bundle);
	}
	

	return res;
  }


