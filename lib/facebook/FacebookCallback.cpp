#include "FacebookCallback.h"
#include "LoggedInEvent.h"
#include "FriendsInvitedEvent.h"

USING_NS_CC;

FacebookCallback::FacebookCallback() {

}

void FacebookCallback::onLogin() {
	auto dispatcher = Director::getInstance()->getEventDispatcher();
	LoggedInEvent event;
	dispatcher->dispatchEvent(&event);
}

void FacebookCallback::onInviteFriendsComplete(std::vector<std::string> friends,
std::string requestId) {
	auto dispatcher = Director::getInstance()->getEventDispatcher();
	FriendsInvitedEvent event(friends, requestId);
	CCLog("Event dispatched");
	dispatcher->dispatchEvent(&event);
}

FacebookCallback::~FacebookCallback() {
}

