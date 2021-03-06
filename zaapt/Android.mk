LOCAL_PATH:= $(call my-dir)

aaptMain := Main.cpp
aaptSources := \
    AaptAssets.cpp \
    AaptConfig.cpp \
    AaptUtil.cpp \
    AaptXml.cpp \
    ApkBuilder.cpp \
    Command.cpp \
    CrunchCache.cpp \
    FileFinder.cpp \
    Images.cpp \
    Package.cpp \
    pseudolocalize.cpp \
    Resource.cpp \
    ResourceFilter.cpp \
    ResourceIdCache.cpp \
    ResourceTable.cpp \
    SourcePos.cpp \
    StringPool.cpp \
    WorkQueue.cpp \
    XMLNode.cpp \
    ZipEntry.cpp \
    ZipFile.cpp \
    Agent.cpp

aaptCFlags := -DAAPT_VERSION=\"$(BUILD_NUMBER)\"
#原来的值，这个应该不影响。
#aaptCFlags := -DAAPT_VERSION=\"$(BUILD_NUMBER_FROM_FILE)\"
#aaptCFlags += -Wall -Werror

aaptCIncludes := \
    external/libpng \
    external/zlib

include $(CLEAR_VARS)

LOCAL_MODULE := libvaapt

LOCAL_SRC_FILES := $(aaptSources) $(aaptMain)
LOCAL_C_INCLUDES += \
    $(aaptCIncludes) 

LOCAL_SHARED_LIBRARIES := \
    libandroidfw \
    libutils \
    libcutils \
    libpng \
    liblog \
    libz \
    libbase

LOCAL_STATIC_LIBRARIES := \
    libexpat_static

LOCAL_CFLAGS += $(aaptCFlags)
LOCAL_CPPFLAGS += -Wno-non-virtual-dtor

# 这里是给.c/.cpp文件添加了一个log库，可以打印log
LOCAL_LDLIBS +=-L$(SYSROOT)/usr/lib -lm -llog

#include $(BUILD_EXECUTABLE)
include $(BUILD_SHARED_LIBRARY)

#改动一：引用的库，除了libexpat，都由STATIC变成SHARE的形式
#改动二：多用了 LOCAL_C_INCLUDES 的引用external/libpng，external/zlib，为什么呢？
#改动三：没有先编译成libaapt库，直接一起编译
#改动四：aaptCFlags 的值少了 -Wall -Werror，这个应该影响不大。

#要弄懂的问题：
#1.aaptCFlags这个变量代表着什么？还有其他一些常见变量的含义
#2.LOCAL_C_INCLUDES是什么含义？什么时候要引用呢？
#3.同样的一些库，什么时候引用动态，什么时候引用静态呢？，获取libandroidfw 依赖其他的库的动态形式？
#4.尝试在改动一些值，向原来的靠近。看看能否编译成功。
#5.改名为vaapt，maim.cpp内的是否要也要改为vaapt，编译push到设备运行就懂了    
































