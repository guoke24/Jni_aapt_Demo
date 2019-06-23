# Jni_aapt_Demo
使用 Jni 调用 aapt 的demo

半成品，包含了使用AndroidStudio生成的头文件的jni调用，和不需要头生成文件的，具有独立jni.cpp和jni.h的jni调用。

aapt在源码不改动的基础上，添加三个文件：Agent.cpp，jni.cpp和jni.h，改动Android.mk文件，编译出.so的动态库，放到AS的该路径：libs/armeabi。

添加的jni.cpp和jni.h文件，当作 java 和 native 层的中介前桥梁，使得native层方法能被java层调用。

添加的Agent.cpp文件，需要具体实现jni特性的native层方法，供java层调用，
其native层函数命名规则为：
```
JNIEXPORT j{返回值类型} JNICALL Java_{JavaApp包名}_{Java类名}_{Java函数名}(JNIEnv *env, jobject jo, ... )
例子：
JNIEXPORT jstring JNICALL Java_com_topwise_jnidemo_MyJni_get(JNIEnv *env, jobject jo)
```


### zaapt路径下的aapt源码，需要在全编成功的源码环境下编译，遍出来的文件是.so。
编译方法：
source build/envsetup.sh

lunch [对应的项目]

mmm [aapt源码根路径]

##### 上述的jni.cpp和jni.h文件，是有模版写好的，直接复制过来就可以使用来，放在源码环境，可以编译成功。

### 而AndroidStudio生成的com_topwise_jnidemo_MyJni.h，该头文件其实可以自己编写（但是只能在As编译，不能在源码编译），格式如下：
```
#include <jni.h>

#ifndef _Included_com_topwise_jnidemo_MyJni
#define _Included_com_topwise_jnidemo_MyJni

#ifdef __cplusplus
extern "C" {
#endif

// 在此声明函数
JNIEXPORT j{返回值类型} JNICALL Java_{JavaApp包名}_{Java类名}_{Java函数名}(JNIEnv *env, jobject jo, ... );

#ifdef __cplusplus
}
#endif
#endif
```

### 头文件中的这两行定义，不使用可以不加
```
#ifndef _Included_com_topwise_jnidemo_MyJni
#define _Included_com_topwise_jnidemo_MyJni
```

###### jni路径下的头文件，其实可以去掉，将其声明放到cpp文件即可。

###### 实现java调用本地函数的文件只能是cpp文件，不能是c文件。

###### 若native层的函数命名中的类名不对应，则java层无法调取成功。

###### mac os 虚拟机环境下，vaapt.so 需要放在 app/src/main/libs/x86_64/ 才会生效

### extern "C"
```
C 和 C++ 对函数的处理方式是不同的. 
extern "C" 是使 C++ 能够调用C写作的库文件的一个手段.
如果要对编译器提示使用C的方式来处理函数的话，那么就要使用extern "C"来说明。
```
详细看链接：https://www.cnblogs.com/yuemw/p/7908413.html
