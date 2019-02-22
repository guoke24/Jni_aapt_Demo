LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := MyJni
LOCAL_SRC_FILES := native.cpp
# 这里是给.c/.cpp文件添加了一个log库，可以打印log
LOCAL_LDLIBS +=-L$(SYSROOT)/usr/lib -lm -llog

include $(BUILD_SHARED_LIBRARY)
