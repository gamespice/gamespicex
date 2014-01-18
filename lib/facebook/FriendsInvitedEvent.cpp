#include "FriendsInvitedEvent.h"

FriendsInvitedEvent::FriendsInvitedEvent(std::vector<std::string> friends,
std::string requestId) :
		EventCustom(std::string("FriendsInvited")) {
	this->friends = friends;
	this->requestId = requestId;
}

FriendsInvitedEvent::~FriendsInvitedEvent() {
}

