#include "Facebook.h"

namespace gamespice {
namespace facebook {

Facebook::Facebook() {
}

Facebook::~Facebook() {
}

void Facebook::login() {
	JNICaller::callStaticVoidMethod("login");
}

void Facebook::share(ShareDTO share) {
	JNICaller::sendMessage(Message("share", share.toBundle()));
}

void Facebook::brag(ShareDTO share) {
	JNICaller::sendMessage(Message("brag", share.toBundle()));
}

void Facebook::inviteFriends(std::string message) {
	JNICaller::callStaticVoidMethodWithString("inviteFriends", message.c_str());
}

void Facebook::postScore(int score) {
	JNICaller::callStaticVoidMethodWithInt("postScore", score);
}

void Facebook::unlockAchievement(std::string achievementUrl) {
	JNICaller::callStaticVoidMethodWithString("unlockAchievement",
			achievementUrl.c_str());
}

} /* namespace facebook */
} /* namespace gamespice */

