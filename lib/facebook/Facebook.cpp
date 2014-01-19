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

} /* namespace facebook */
} /* namespace gamespice */

