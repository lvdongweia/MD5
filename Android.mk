LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES:= \
	example.c \
	md5.c \
	md5_lib.c \
	hash.c

LOCAL_SHARED_LIBRARIES := \
    libcutils \
    libutils \
    libnetutils

LOCAL_C_INCLUDES := \
    bionic \
    $(LOCAL_PATH)/

LOCAL_MODULE_TAGS := eng optional
LOCAL_CFLAGS := -O2 -Wall -g
LOCAL_MODULE:= md5_example

include $(BUILD_EXECUTABLE)
