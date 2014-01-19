/*
 * LoggedInListener.cpp
 *
 *  Created on: Jan 19, 2014
 *      Author: vini
 */

#include "LoggedInListener.h"

LoggedInListener* LoggedInListener::create(
std::function<void(LoggedInEvent*)> callback) {
	auto listener = new LoggedInListener();
	if (listener && listener->init("LoggedIn", callback)) {
		listener->autorelease();
	} else {
		CC_SAFE_DELETE(listener);
	}
	return listener;
}

bool LoggedInListener::checkAvailable() {
	return EventListener::checkAvailable() && _onLoggedInEvent != nullptr;
}

LoggedInListener* LoggedInListener::clone() {
	auto listener = new LoggedInListener();
	if (listener && listener->init(_listenerID, _onLoggedInEvent)) {
		listener->autorelease();
	} else {
		CC_SAFE_DELETE(listener);
	}
	return listener;
}

LoggedInListener::LoggedInListener() :
		_onLoggedInEvent(nullptr) {

}

LoggedInListener::~LoggedInListener() {
}

bool LoggedInListener::init(ListenerID listenerId,
std::function<void(LoggedInEvent*)> callback) {
	_onLoggedInEvent = callback;

	auto listener = [this](Event* event) {
		if (_onLoggedInEvent != nullptr)
		{
			_onLoggedInEvent(static_cast<LoggedInEvent*>(event));
		}
	};

	return EventListener::init(EventListener::Type::CUSTOM, listenerId,
			listener);
}
