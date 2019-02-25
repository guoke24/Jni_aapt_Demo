# APP_ABI := arm64-v8a armeabi-v7a armeabi
APP_STL := c++_static
APP_CPPFLAGS := -frtti -fexceptions
# APP_ABI：是将要生成哪些cpu类型的so，all代表全部
APP_ABI := armeabi-v7a
# APP_PLATFORM：生成的so的最低android版本
APP_PLATFORM := android-16