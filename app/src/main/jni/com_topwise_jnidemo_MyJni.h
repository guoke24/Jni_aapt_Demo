/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_topwise_zlkeypos_MyJni */
// java层去调用c++层函数的时候，是通过包名+类名+函数名来找的
// 所以这里的名字鼻祖对应java的包名+类名+函数名
#ifndef _Included_com_topwise_jnidemo_MyJni
#define _Included_com_topwise_jnidemo_MyJni
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_topwise_zlkeypos_MyJni
 * Method:    get
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_topwise_jnidemo_MyJni_get
  (JNIEnv *, jobject);

/*
 * Class:     com_topwise_zlkeypos_MyJni
 * Method:    send
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_topwise_jnidemo_MyJni_send
  (JNIEnv *, jobject, jstring);

#ifdef __cplusplus
}
#endif
#endif
