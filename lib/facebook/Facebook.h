#ifndef FACEBOOK_H_
#define FACEBOOK_H_

#include "FriendsInvitedEvent.h"
#include "FriendsInvitedListener.h"
#include "ShareCompletedEvent.h"
#include "ShareCompletedListener.h"
#include "LoggedInEvent.h"
#include "LoggedInListener.h"
#include "BragCompletedEvent.h"
#include "BragCompletedListener.h"
#include "../platform/android/jni/JNICaller.h"

using namespace gamespice::android;

namespace gamespice {
namespace facebook {

class Facebook {
public:
	Facebook();

	void static login();
	void static share(std::string name);
	void static brag(std::string message);

	virtual ~Facebook();
};

} /* namespace facebook */
} /* namespace gamespice */

#endif /* FACEBOOK_H_ */
