#include "FriendsInvitedEvent.h"

const std::string FriendsInvitedEvent::NAME = { "FriendsInvitedEvent" };

FriendsInvitedEvent::FriendsInvitedEvent(std::vector<std::string> friends,
std::string requestId) :
		EventCustom(FriendsInvitedEvent::NAME) {
	this->friends = friends;
	this->requestId = requestId;
}

FriendsInvitedEvent::~FriendsInvitedEvent() {
}

