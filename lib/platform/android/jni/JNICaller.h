/*
 * JNICaller.h
 *
 *  Created on: Jan 19, 2014
 *      Author: vini
 */

#ifndef JNICALLER_H_
#define JNICALLER_H_

#include <jni.h>
#include "platform/android/jni/JniHelper.h"
#include <string>
#include "Message.h"

USING_NS_CC;

namespace gamespice {
namespace android {

class JNICaller {
public:
	JNICaller();

	void static callStaticVoidMethodWithString(const char* name,
			const char* idName);

	void static callStaticVoidMethodWithStringAndInt(const char* name,
			const char* idName, const int value);

	void static callStaticVoidMethod(const char* name);

	bool static callStaticBoolMethod(const char* name);

	void static sendMessage(Message message);

	virtual ~JNICaller();

private:
	static std::string GAME_SPICE_CLASS;
};

} /* namespace android */
} /* namespace gamespice */

#endif /* JNICALLER_H_ */
