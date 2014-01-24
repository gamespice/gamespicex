#ifndef FACEBOOKCALLBACK_H_
#define FACEBOOKCALLBACK_H_

#include "cocos2d.h"
#include <string>
#include <vector>
#include "LoggedInEvent.h"
#include "FriendsInvitedEvent.h"
#include "ShareCompletedEvent.h"
#include "BragCompletedEvent.h"
#include "PostScoreCompletedEvent.h"
#include "UnlockAchievementCompletedEvent.h"

class FacebookCallback {
public:
	FacebookCallback();
	void onLogin();
	void onInviteFriendsComplete(std::vector<std::string> friends,
	std::string invitedFriends);
	void onShareComplete(std::string postId);
	void onBragComplete(std::string postId);
	void onPostScoreComplete();
	void onUnlockAchievementComplete();
	virtual ~FacebookCallback();
};

#endif /* FACEBOOKCALLBACK_H_ */
