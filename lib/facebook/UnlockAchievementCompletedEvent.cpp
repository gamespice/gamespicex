/*
 * UnlockAchievementCompletedEvent.cpp
 *
 *  Created on: Jan 24, 2014
 *      Author: vini
 */

#include "UnlockAchievementCompletedEvent.h"

const std::string UnlockAchievementCompletedEvent::NAME = {
		"UnlockAchievementCompletedEvent" };

UnlockAchievementCompletedEvent::UnlockAchievementCompletedEvent() :
		EventCustom(UnlockAchievementCompletedEvent::NAME) {

}

UnlockAchievementCompletedEvent::~UnlockAchievementCompletedEvent() {
}
