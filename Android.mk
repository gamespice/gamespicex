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
lib/facebook/ShareCompletedEvent.cpp \
lib/facebook/ShareCompletedListener.cpp \
lib/facebook/BragCompletedEvent.cpp \
lib/facebook/BragCompletedListener.cpp \
lib/facebook/FriendsInvitedEvent.cpp \
lib/facebook/FriendsInvitedListener.cpp \
lib/facebook/LoggedInEvent.cpp \
lib/facebook/LoggedInListener.cpp \
lib/facebook/FacebookCallback.cpp \
lib/facebook/FacebookCallback_wrap.cpp \
lib/platform/android/jni/JNICaller.cpp \
vendor/jansson/src/dump.c \
vendor/jansson/src/error.c \
vendor/jansson/src/hashtable.c \
vendor/jansson/src/load.c \
vendor/jansson/src/memory.c \
vendor/jansson/src/pack_unpack.c \
vendor/jansson/src/strbuffer.c \
vendor/jansson/src/strconv.c \
vendor/jansson/src/utf.c \
vendor/jansson/src/value.c

LOCAL_WHOLE_STATIC_LIBRARIES := cocos2dx_static cocos_network_static

LOCAL_C_INCLUDES := $(LOCAL_PATH)/lib \
$(LOCAL_PATH)/vendor/jansson/src \
$(LOCAL_PATH)/vendor/jansson/android

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/lib

include $(BUILD_STATIC_LIBRARY)

$(call import-module,network)
