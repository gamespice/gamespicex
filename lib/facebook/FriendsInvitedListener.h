/*
 * FriendsInvitedListener.h
 *
 *  Created on: Jan 18, 2014
 *      Author: vini
 */

#ifndef FRIENDSINVITEDLISTENER_H_
#define FRIENDSINVITEDLISTENER_H_

#include "cocos2d.h"
#include "FriendsInvitedEvent.h"

USING_NS_CC;

class FriendsInvitedListener: public EventListener {
public:

	static FriendsInvitedListener* create(
			std::function<void(FriendsInvitedEvent*)> callback);

	virtual bool checkAvailable() override;
	virtual FriendsInvitedListener* clone() override;

	virtual ~FriendsInvitedListener();

protected:
	FriendsInvitedListener();

	bool init(ListenerID listenerId,
			std::function<void(FriendsInvitedEvent*)> callback);

	std::function<void(FriendsInvitedEvent*)> _onFriendsInvitedEvent;
};

#endif /* FRIENDSINVITEDLISTENER_H_ */
