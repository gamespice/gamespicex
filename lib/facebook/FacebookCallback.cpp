#include "FacebookCallback.h"

USING_NS_CC;

void dispatch(EventCustom event) {
	auto dispatcher = Director::getInstance()->getEventDispatcher();
	dispatcher->dispatchEvent(&event);
}

FacebookCallback::FacebookCallback() {

}

void FacebookCallback::onLogin() {
	dispatch(LoggedInEvent());
}

void FacebookCallback::onInviteFriendsComplete(std::vector<std::string> friends,
std::string requestId) {
	dispatch(FriendsInvitedEvent(friends, requestId));
}

void FacebookCallback::onShareComplete(std::string postId) {
	dispatch(ShareCompletedEvent(postId));
}

void FacebookCallback::onBragComplete(std::string postId) {
	dispatch(BragCompletedEvent(postId));
}

FacebookCallback::~FacebookCallback() {
}

