LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_STATIC_LIBRARIES := liblog
LOCAL_MODULE    := libmshook
LOCAL_SRC_FILES := \
	$(LOCAL_PATH)ARM.cpp \
	Thumb.cpp \
	x86.cpp \
	x86_64.cpp \
	Debug.cpp \
	Hooker.cpp \
	PosixMemory.cpp
include $(BUILD_STATIC_LIBRARY)