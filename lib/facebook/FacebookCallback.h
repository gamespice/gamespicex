#ifndef FACEBOOKCALLBACK_H_
#define FACEBOOKCALLBACK_H_

#include "cocos2d.h"
#include <string>
#include <vector>
#include "FriendsInvitedEvent.h"

class FacebookCallback {
public:
	FacebookCallback();
	void onLogin();
	void onInviteFriendsComplete(std::vector<std::string> friends, std::string invitedFriends);
	virtual ~FacebookCallback();
};

#endif /* FACEBOOKCALLBACK_H_ */
