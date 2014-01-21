/*
 * BragCompetedEvent.h
 *
 *  Created on: Jan 21, 2014
 *      Author: vini
 */

#ifndef BRAGCOMPLETEDEVENT_H_
#define BRAGCOMPLETEDEVENT_H_

#include "cocos2d.h"
#include "string"

USING_NS_CC;

class BragCompletedEvent: public EventCustom {
public:
	BragCompletedEvent(std::string postId);
	virtual ~BragCompletedEvent();

	std::string postId;
};

#endif /* BRAGCOMPLETEDEVENT_H_ */
