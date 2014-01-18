/*
 * FriendsInvitedListener.cpp
 *
 *  Created on: Jan 18, 2014
 *      Author: vini
 */

#include "FriendsInvitedListener.h"

FriendsInvitedListener* FriendsInvitedListener::create(
		std::function<void(FriendsInvitedEvent*)> callback) {

	auto listener = new FriendsInvitedListener();
	if (listener && listener->init("FriendsInvited", callback)) {
		listener->autorelease();
	} else {
		CC_SAFE_DELETE(listener);
	}
	return listener;
}

bool FriendsInvitedListener::checkAvailable() {
	return EventListener::checkAvailable() && _onFriendsInvitedEvent != nullptr;
}

FriendsInvitedListener* FriendsInvitedListener::clone() {
	auto listener = new FriendsInvitedListener();
	if (listener && listener->init(_listenerID, _onFriendsInvitedEvent)) {
		listener->autorelease();
	} else {
		CC_SAFE_DELETE(listener);
	}
	return listener;
}

FriendsInvitedListener::FriendsInvitedListener() :
		_onFriendsInvitedEvent(nullptr) {

}

FriendsInvitedListener::~FriendsInvitedListener() {
}

bool FriendsInvitedListener::init(ListenerID listenerId,
		std::function<void(FriendsInvitedEvent*)> callback) {

	_onFriendsInvitedEvent = callback;

	auto listener = [this](Event* event) {
		if (_onFriendsInvitedEvent != nullptr)
		{
			_onFriendsInvitedEvent(static_cast<FriendsInvitedEvent*>(event));
		}
	};

	return EventListener::init(EventListener::Type::CUSTOM, listenerId,
			listener);
}
