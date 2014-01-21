/*
 * BragCompetedEvent.cpp
 *
 *  Created on: Jan 21, 2014
 *      Author: vini
 */

#include "BragCompletedEvent.h"

BragCompletedEvent::BragCompletedEvent(std::string postId) :
		postId(postId), EventCustom(std::string("BragCompleted")) {

}

BragCompletedEvent::~BragCompletedEvent() {
}

