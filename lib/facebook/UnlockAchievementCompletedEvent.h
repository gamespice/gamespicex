/*
 * UnlockAchievementCompletedEvent.h
 *
 *  Created on: Jan 24, 2014
 *      Author: vini
 */

#ifndef UNLOCKACHIEVEMENTCOMPLETEDEVENT_H_
#define UNLOCKACHIEVEMENTCOMPLETEDEVENT_H_

#include "cocos2d.h"
#include "string"

USING_NS_CC;

class UnlockAchievementCompletedEvent: public EventCustom {
public:
	UnlockAchievementCompletedEvent();
	virtual ~UnlockAchievementCompletedEvent();

	static const std::string NAME;
};

#endif /* UNLOCKACHIEVEMENTCOMPLETEDEVENT_H_ */
