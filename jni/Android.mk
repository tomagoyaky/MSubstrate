LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_LDLIBS 	:= -llog -fPIC
LOCAL_LDFLAGS += -pie -fPIE
LOCAL_MODULE    := libmshook
LOCAL_SRC_FILES := \
	Tester.cpp \
	ARM.cpp \
	Thumb.cpp \
	x86.cpp \
	x86_64.cpp \
	Debug.cpp \
	Hooker.cpp \
	PosixMemory.cpp \
	util.cpp
	
include $(BUILD_EXECUTABLE)
#include $(BUILD_STATIC_LIBRARY)