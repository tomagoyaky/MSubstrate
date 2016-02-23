LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
APP_ABI := armeabi x86 armeabi-v7a 
LOCAL_LDLIBS 	:= -llog -fPIC
LOCAL_LDFLAGS += -pie -fPIE
LOCAL_MODULE    := Tester
#LOCAL_MODULE    := mshook
LOCAL_SRC_FILES := \
	hook.cpp \
	Tester.cpp \
	libmshook/ARM.cpp \
	libmshook/Thumb.cpp \
	libmshook/x86.cpp \
	libmshook/x86_64.cpp \
	libmshook/Debug.cpp \
	libmshook/Hooker.cpp \
	libmshook/PosixMemory.cpp \
	libmshook/util.cpp
LOCAL_C_INCLUDES :=  $(LOCAL_PATH) \
	$(LOCAL_PATH)/libmshook
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)
	
include $(BUILD_EXECUTABLE)
#include $(BUILD_STATIC_LIBRARY)