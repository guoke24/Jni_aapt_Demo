# Jni_aapt_Demo
使用 Jni 调用 aapt 的demo

半成品，包含了使用AndroidStudio生成的头文件的jni调用，和不需要头生成文件的，具有独立jni.cpp和jni.h的jni调用。
aapt在源码不改动的基础上，添加一个Agent.cpp文件，当作 java 和 native 层的中介。Agent.cpp需要实现供java层调用的native层方法，
其方法函数命名规则为：
JNIEXPORT j{返回值类型} JNICALL Java_{JavaApp包名}_{Java类名}_{Java函数名}(JNIEnv *env, jobject jo, ... )
JNIEXPORT jstring JNICALL Java_com_topwise_jnidemo_MyJni_get(JNIEnv *env, jobject jo)

zaapt路径下的aapt源码，需要在全编成功的源码环境下编译。
编译方法：
source build/envsetup.sh
lunch [对应的项目]
mmm [aapt源码根路径]


