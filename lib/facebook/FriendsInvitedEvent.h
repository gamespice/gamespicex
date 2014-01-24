#ifndef FRIENDSINVITEDEVENT_H_
#define FRIENDSINVITEDEVENT_H_

#include "cocos2d.h"
#include <string>
#include <vector>

USING_NS_CC;

class FriendsInvitedEvent: public EventCustom {
public:
	FriendsInvitedEvent(std::vector<std::string> friends,
	std::string requestId);
	virtual ~FriendsInvitedEvent();

	std::vector<std::string> friends;std::string requestId;

	static const std::string NAME;
};

#endif /* FRIENDSINVITEDEVENT_H_ */
