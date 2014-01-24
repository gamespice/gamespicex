/*
 * LoginEvent.h
 *
 *  Created on: Jan 19, 2014
 *      Author: vini
 */

#ifndef LOGINEVENT_H_
#define LOGINEVENT_H_

#include "cocos2d.h"
#include "string"

USING_NS_CC;

class LoggedInEvent: public EventCustom {
public:
	LoggedInEvent();
	virtual ~LoggedInEvent();

	static const std::string NAME;
};

#endif /* LOGINEVENT_H_ */
