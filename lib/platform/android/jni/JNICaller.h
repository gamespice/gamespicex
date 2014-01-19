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

USING_NS_CC;

namespace gamespice {
namespace android {

class JNICaller {
public:
	JNICaller();

	void static callVoidMethodWithString(const char* name, const char* idName);

	void static callStaticVoidMethod(const char* name);

	bool static callStaticBoolMethod(const char* name);

	void static callVoidMethodWithStringAndInt(const char* name,
			const char* idName, const int value);

	virtual ~JNICaller();

private:
	static std::string GAME_SPICE_CLASS;
};

} /* namespace android */
} /* namespace gamespice */

#endif /* JNICALLER_H_ */
