/*
 * BragCompetedEvent.cpp
 *
 *  Created on: Jan 21, 2014
 *      Author: vini
 */

#include "BragCompletedEvent.h"

const std::string BragCompletedEvent::NAME = {"BragCompletedEvent"};

BragCompletedEvent::BragCompletedEvent(std::string postId) :
		postId(postId), EventCustom(BragCompletedEvent::NAME) {

}

BragCompletedEvent::~BragCompletedEvent() {
}

