/*
 * PostScoreCompletedEvent.cpp
 *
 *  Created on: Jan 24, 2014
 *      Author: vini
 */

#include "PostScoreCompletedEvent.h"

const std::string PostScoreCompletedEvent::NAME = { "PostScoreCompletedEvent" };

PostScoreCompletedEvent::PostScoreCompletedEvent() :
		EventCustom(PostScoreCompletedEvent::NAME) {

}

PostScoreCompletedEvent::~PostScoreCompletedEvent() {
}
