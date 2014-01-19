#ifndef FACEBOOK_H_
#define FACEBOOK_H_

#include "FriendsInvitedEvent.h"
#include "FriendsInvitedListener.h"
#include "LoggedInEvent.h"
#include "LoggedInListener.h"
#include "../platform/android/jni/JNICaller.h"

using namespace gamespice::android;

namespace gamespice {
namespace facebook {

class Facebook {
public:
	Facebook();

	void static login();

	virtual ~Facebook();
};

} /* namespace facebook */
} /* namespace gamespice */

#endif /* FACEBOOK_H_ */
