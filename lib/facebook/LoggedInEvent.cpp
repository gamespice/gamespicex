/*
 * LoginEvent.cpp
 *
 *  Created on: Jan 19, 2014
 *      Author: vini
 */

#include "LoggedInEvent.h"

const std::string LoggedInEvent::NAME = { "LoggedInEvent" };

LoggedInEvent::LoggedInEvent() :
		EventCustom(LoggedInEvent::NAME) {

}

LoggedInEvent::~LoggedInEvent() {
}
