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

void Facebook::share(std::string name) {
	JNICaller::callStaticVoidMethodWithString("share", name.c_str());
}

void Facebook::brag(std::string message) {
	JNICaller::callStaticVoidMethodWithString("brag", message.c_str());
}

} /* namespace facebook */
} /* namespace gamespice */

