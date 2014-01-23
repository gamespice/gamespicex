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

} /* namespace facebook */
} /* namespace gamespice */

