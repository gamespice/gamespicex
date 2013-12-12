LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := gamespice_x_static

LOCAL_MODULE_FILENAME := libgamespicex

LOCAL_SRC_FILES := \
lib/Models/User.cpp \
lib/Models/Fund.cpp \
lib/Models/Leaderboard.cpp \
lib/JSON.cpp \
lib/APIClient.cpp \
lib/GameSpice.cpp \
lib/json/cJSON/cJSON.c \
lib/json/CCJSONConverter.cpp

LOCAL_WHOLE_STATIC_LIBRARIES := cocos2dx_static cocos_extension_static

LOCAL_C_INCLUDES := $(LOCAL_PATH)/lib

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/lib

include $(BUILD_STATIC_LIBRARY)

$(call import-module,cocos2dx)
$(call import-module,cocos2dx/platform/third_party/android/prebuilt/libcurl)
$(call import-module,extensions)
