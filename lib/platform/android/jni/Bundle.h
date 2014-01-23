/*
 * Bundle.h
 *
 *  Created on: Jan 23, 2014
 *      Author: vini
 */

#ifndef BUNDLE_H_
#define BUNDLE_H_

#include "cocos2d.h"
#include "map"
#include "../../../jansson/jansson.h"

USING_NS_CC;

namespace gamespice {
namespace android {

class Bundle {
public:
	Bundle();
	Bundle add(std::string key, std::string value);
	Bundle add(std::string key, int value);
	Bundle add(std::string key, bool value);
	virtual ~Bundle();

	friend class Message;

private:
	std::map<std::string, Value> data;

	void toJSON(json_t* jsonObject);
};

} /* namespace android */
} /* namespace gamespice */

#endif /* BUNDLE_H_ */
