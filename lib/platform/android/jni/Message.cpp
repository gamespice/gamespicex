/*
 * Message.cpp
 *
 *  Created on: Jan 23, 2014
 *      Author: vini
 */

#include "Message.h"

namespace gamespice {
namespace android {

Message::Message(std::string action, Bundle bundle) :
		action(action), bundle(bundle) {

}

std::string Message::toJSON() {
	json_t* jsonMessage = json_object();
	json_object_set_new(jsonMessage, "action", json_string(action.c_str()));
	json_t* jsonObject = json_object();
	bundle.toJSON(jsonObject);
	json_object_set_new(jsonMessage, "data", jsonObject);
	char* jsonStrLocal = json_dumps(jsonMessage,
	JSON_COMPACT | JSON_ENSURE_ASCII);
	std::string jsonStr(jsonStrLocal);
	json_decref(jsonObject);
	json_decref(jsonMessage);
	return jsonStr;
}

Message::~Message() {
}

} /* namespace android */
} /* namespace gamespice */
