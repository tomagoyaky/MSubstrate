LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_LDLIBS 	:= -llog -fPIC
LOCAL_LDFLAGS += -pie -fPIE
LOCAL_MODULE    := mshook
LOCAL_SRC_FILES := \
	ARM.cpp \
	Thumb.cpp \
	x86.cpp \
	x86_64.cpp \
	Debug.cpp \
	Hooker.cpp \
	PosixMemory.cpp \
	util.cpp
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)
	
#include $(BUILD_EXECUTABLE)
include $(BUILD_STATIC_LIBRARY)