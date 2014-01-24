/*
 * ShareCompletedEvent.cpp
 *
 *  Created on: Jan 21, 2014
 *      Author: vini
 */

#include "ShareCompletedEvent.h"

const std::string ShareCompletedEvent::NAME = { "ShareCompletedEvent" };

ShareCompletedEvent::ShareCompletedEvent(std::string postId) :
		postId(postId), EventCustom(ShareCompletedEvent::NAME) {

}

ShareCompletedEvent::~ShareCompletedEvent() {
}

