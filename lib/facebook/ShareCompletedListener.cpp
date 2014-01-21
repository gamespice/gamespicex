/*
 * ShareCompletedListener.cpp
 *
 *  Created on: Jan 21, 2014
 *      Author: vini
 */

#include "ShareCompletedListener.h"

ShareCompletedListener* ShareCompletedListener::create(
std::function<void(ShareCompletedEvent*)> callback) {
	auto listener = new ShareCompletedListener();
	if (listener && listener->init("ShareCompleted", callback)) {
		listener->autorelease();
	} else {
		CC_SAFE_DELETE(listener);
	}
	return listener;
}

bool ShareCompletedListener::checkAvailable() {
	return EventListener::checkAvailable() && _onShareCompletedEvent != nullptr;
}

ShareCompletedListener* ShareCompletedListener::clone() {
	auto listener = new ShareCompletedListener();
	if (listener && listener->init(_listenerID, _onShareCompletedEvent)) {
		listener->autorelease();
	} else {
		CC_SAFE_DELETE(listener);
	}
	return listener;
}

ShareCompletedListener::ShareCompletedListener() :
		_onShareCompletedEvent(nullptr) {

}

ShareCompletedListener::~ShareCompletedListener() {
}

bool ShareCompletedListener::init(ListenerID listenerId,
std::function<void(ShareCompletedEvent*)> callback) {
	_onShareCompletedEvent = callback;

	auto listener = [this](Event* event) {
		if (_onShareCompletedEvent != nullptr)
		{
			_onShareCompletedEvent(static_cast<ShareCompletedEvent*>(event));
		}
	};

	return EventListener::init(EventListener::Type::CUSTOM, listenerId,
			listener);
}
