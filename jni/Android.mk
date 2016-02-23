LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
subdirs := $(addprefix $(LOCAL_PATH)/,$(addsuffix /Android.mk, \
	libmshook \
))
include $(subdirs)

include $(CLEAR_VARS)
LOCAL_LDLIBS 	:= -llog -fPIC
LOCAL_LDFLAGS += -pie -fPIE
LOCAL_MODULE    := Tester
LOCAL_SRC_FILES := Tester.cpp
LOCAL_C_INCLUDES := $(LOCAL_PATH)/libmshook	
LOCAL_STATIC_LIBRARIES := libmshook
	
include $(BUILD_EXECUTABLE)
#include $(BUILD_STATIC_LIBRARY)