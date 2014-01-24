#ifndef FACEBOOK_H_
#define FACEBOOK_H_

#include "FriendsInvitedEvent.h"
#include "ShareCompletedEvent.h"
#include "LoggedInEvent.h"
#include "BragCompletedEvent.h"
#include "PostScoreCompletedEvent.h"
#include "UnlockAchievementCompletedEvent.h"
#include "../platform/android/jni/JNICaller.h"
#include "../platform/android/jni/dto/ShareDTO.h"

using namespace gamespice::android;

namespace gamespice {
namespace facebook {

class Facebook {
public:
	Facebook();

	void static login();
	void static share(ShareDTO share);
	void static brag(ShareDTO share);
	void static inviteFriends(std::string message);
	void static postScore(int score);
	void static unlockAchievement(std::string achievementUrl);

	virtual ~Facebook();
};

} /* namespace facebook */
} /* namespace gamespice */

#endif /* FACEBOOK_H_ */
