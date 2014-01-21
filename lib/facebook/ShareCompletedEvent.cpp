/*
 * ShareCompletedEvent.cpp
 *
 *  Created on: Jan 21, 2014
 *      Author: vini
 */

#include "ShareCompletedEvent.h"

ShareCompletedEvent::ShareCompletedEvent(std::string postId) :
		postId(postId), EventCustom(std::string("ShareCompleted")) {

}

ShareCompletedEvent::~ShareCompletedEvent() {
}

