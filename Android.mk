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
lib/facebook/BragCompletedEvent.cpp \
lib/facebook/FriendsInvitedEvent.cpp \
lib/facebook/LoggedInEvent.cpp \
lib/facebook/PostScoreCompletedEvent.cpp \
lib/facebook/UnlockAchievementCompletedEvent.cpp \
lib/facebook/FacebookCallback.cpp \
lib/facebook/FacebookCallback_wrap.cpp \
lib/platform/android/jni/JNICaller.cpp \
lib/platform/android/jni/Message.cpp \
lib/platform/android/jni/Bundle.cpp \
lib/platform/android/jni/dto/ShareDTO.cpp \
lib/jansson/dump.c \
lib/jansson/error.c \
lib/jansson/hashtable.c \
lib/jansson/load.c \
lib/jansson/memory.c \
lib/jansson/pack_unpack.c \
lib/jansson/strbuffer.c \
lib/jansson/strconv.c \
lib/jansson/utf.c \
lib/jansson/value.c

LOCAL_WHOLE_STATIC_LIBRARIES := cocos2dx_static cocos_network_static

LOCAL_C_INCLUDES := $(LOCAL_PATH)/lib \
$(LOCAL_PATH)/lib/jansson \

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/lib

include $(BUILD_STATIC_LIBRARY)

$(call import-module,network)
