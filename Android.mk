LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := gamespice_static

LOCAL_MODULE_FILENAME := libgamespice

LOCAL_SRC_FILES := lib/models/User.cpp \
lib/models/Fund.cpp \
lib/models/InventoryItem.cpp \
lib/models/Inventory.cpp \
lib/models/Order.cpp \
lib/models/Leaderboard.cpp \
lib/JSON.cpp \
lib/APIClient.cpp \
lib/GameSpice.cpp \
lib/json/cJSON/cJSON.c \
lib/json/CCJSONConverter.cpp \
lib/facebook/Facebook.cpp \
lib/facebook/FriendsInvitedEvent.cpp \
lib/facebook/FriendsInvitedListener.cpp \
lib/facebook/LoggedInEvent.cpp \
lib/facebook/LoggedInListener.cpp \
lib/facebook/FacebookCallback.cpp \
lib/facebook/FacebookCallback_wrap.cpp \
lib/platform/android/jni/JNICaller.cpp

LOCAL_WHOLE_STATIC_LIBRARIES := cocos2dx_static cocos_network_static

LOCAL_C_INCLUDES := $(LOCAL_PATH)/lib

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/lib

include $(BUILD_STATIC_LIBRARY)

$(call import-module,network)