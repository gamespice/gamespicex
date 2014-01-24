/*
 * PostScoreCompletedEvent.h
 *
 *  Created on: Jan 24, 2014
 *      Author: vini
 */

#ifndef POSTSCORECOMPLETEDEVENT_H_
#define POSTSCORECOMPLETEDEVENT_H_

#include "cocos2d.h"

USING_NS_CC;

class PostScoreCompletedEvent: public EventCustom {
public:
	PostScoreCompletedEvent();
	virtual ~PostScoreCompletedEvent();

	static const std::string NAME;
};

#endif /* POSTSCORECOMPLETEDEVENT_H_ */
