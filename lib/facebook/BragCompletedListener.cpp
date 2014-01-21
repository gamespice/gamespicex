/*
 * BragCompletedListener.cpp
 *
 *  Created on: Jan 21, 2014
 *      Author: vini
 */

#include "BragCompletedListener.h"

BragCompletedListener* BragCompletedListener::create(
std::function<void(BragCompletedEvent*)> callback) {
	auto listener = new BragCompletedListener();
	if (listener && listener->init("BragCompleted", callback)) {
		listener->autorelease();
	} else {
		CC_SAFE_DELETE(listener);
	}
	return listener;
}

bool BragCompletedListener::checkAvailable() {
	return EventListener::checkAvailable() && _onBragCompletedEvent != nullptr;
}

BragCompletedListener* BragCompletedListener::clone() {
	auto listener = new BragCompletedListener();
	if (listener && listener->init(_listenerID, _onBragCompletedEvent)) {
		listener->autorelease();
	} else {
		CC_SAFE_DELETE(listener);
	}
	return listener;
}

BragCompletedListener::~BragCompletedListener() {
}

BragCompletedListener::BragCompletedListener() :
		_onBragCompletedEvent(nullptr) {
}

bool BragCompletedListener::init(ListenerID listenerId,
std::function<void(BragCompletedEvent*)> callback) {
	_onBragCompletedEvent = callback;

	auto listener = [this](Event* event) {
		if (_onBragCompletedEvent != nullptr)
		{
			_onBragCompletedEvent(static_cast<BragCompletedEvent*>(event));
		}
	};

	return EventListener::init(EventListener::Type::CUSTOM, listenerId,
			listener);
}
