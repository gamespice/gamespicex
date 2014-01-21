/*
 * JNICaller.cpp
 *
 *  Created on: Jan 19, 2014
 *      Author: vini
 */

#include "JNICaller.h"

namespace gamespice {
namespace android {

std::string JNICaller::GAME_SPICE_CLASS = std::string(
		"io/gamespice/android/GameSpice");

JNICaller::JNICaller() {

}

void JNICaller::callStaticVoidMethodWithStringAndInt(const char* name,
		const char* idName, const int value) {
	cocos2d::JniMethodInfo t;
	if (cocos2d::JniHelper::getStaticMethodInfo(t,
			JNICaller::GAME_SPICE_CLASS.c_str(), name,
			"(Ljava/lang/String;I)V")) {
		jstring jIdName = t.env->NewStringUTF(idName);
		t.env->CallStaticVoidMethod(t.classID, t.methodID, jIdName,
				(jint) value);
		t.env->DeleteLocalRef(t.classID);
		t.env->DeleteLocalRef(jIdName);
	}
}

bool JNICaller::callStaticBoolMethod(const char* name) {
	cocos2d::JniMethodInfo t;
	if (cocos2d::JniHelper::getStaticMethodInfo(t,
			JNICaller::GAME_SPICE_CLASS.c_str(), name, "()Z")) {
		bool result = (t.env->CallStaticBooleanMethod(t.classID, t.methodID)
				== JNI_TRUE);
		t.env->DeleteLocalRef(t.classID);
		return result;
	} else {
		return false;
	}
}

void JNICaller::callStaticVoidMethod(const char* name) {
	cocos2d::JniMethodInfo t;
	if (cocos2d::JniHelper::getStaticMethodInfo(t,
			JNICaller::GAME_SPICE_CLASS.c_str(), name, "()V")) {
		t.env->CallStaticVoidMethod(t.classID, t.methodID);
		t.env->DeleteLocalRef(t.classID);
	}
}

void JNICaller::callStaticVoidMethodWithString(const char* name, const char* idName) {
	cocos2d::JniMethodInfo t;
	if (cocos2d::JniHelper::getStaticMethodInfo(t,
			JNICaller::GAME_SPICE_CLASS.c_str(), name,
			"(Ljava/lang/String;)V")) {
		jstring jIdName = t.env->NewStringUTF(idName);
		t.env->CallStaticVoidMethod(t.classID, t.methodID, jIdName);
		t.env->DeleteLocalRef(t.classID);
		t.env->DeleteLocalRef(jIdName);
	}
}

JNICaller::~JNICaller() {
}

} /* namespace android */
} /* namespace gamespice */
