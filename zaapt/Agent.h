#include "jni.h"


#ifndef _Included_Agent
#define _Included_Agent
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

/*
 * Class:     com_topwise_zlkeypos_MyJni
 * Method:    send
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jint JNICALL Java_com_topwise_jnidemo_MyJni_aapt
  (JNIEnv *, jobject, jstring, jstring);

#ifdef __cplusplus
}
#endif
#endif



