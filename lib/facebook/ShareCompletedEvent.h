/*
 * ShareCompletedEvent.h
 *
 *  Created on: Jan 21, 2014
 *      Author: vini
 */

#ifndef SHARECOMPLETEDEVENT_H_
#define SHARECOMPLETEDEVENT_H_

#include "cocos2d.h"
#include "string"

USING_NS_CC;

class ShareCompletedEvent: public EventCustom {
public:
	ShareCompletedEvent(std::string postId);
	virtual ~ShareCompletedEvent();

	std::string postId;
};

#endif /* SHARECOMPLETEDEVENT_H_ */
