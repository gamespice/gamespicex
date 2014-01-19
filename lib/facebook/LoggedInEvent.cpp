/*
 * LoginEvent.cpp
 *
 *  Created on: Jan 19, 2014
 *      Author: vini
 */

#include "LoggedInEvent.h"

LoggedInEvent::LoggedInEvent() :
		EventCustom(std::string("LoggedIn")) {

}

LoggedInEvent::~LoggedInEvent() {
}
