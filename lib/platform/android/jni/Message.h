/*
 * Message.h
 *
 *  Created on: Jan 23, 2014
 *      Author: vini
 */

#ifndef MESSAGE_H_
#define MESSAGE_H_

#include "Bundle.h"

#include <string>
#include "../../../jansson/jansson.h"

namespace gamespice {
namespace android {

class Message {
public:
	Message(std::string action, Bundle bundle);

	std::string toJSON();

	virtual ~Message();

private:

	std::string action;
	Bundle bundle;
};

} /* namespace android */
} /* namespace gamespice */

#endif /* MESSAGE_H_ */
