/*
 * ShareCompletedListener.h
 *
 *  Created on: Jan 21, 2014
 *      Author: vini
 */

#ifndef SHARECOMPLETEDLISTENER_H_
#define SHARECOMPLETEDLISTENER_H_

#include "cocos2d.h"
#include "ShareCompletedEvent.h"

USING_NS_CC;

class ShareCompletedListener: public EventListener {
public:
	static ShareCompletedListener* create(
	std::function<void(ShareCompletedEvent*)> callback);

	virtual bool checkAvailable() override;
	virtual ShareCompletedListener* clone() override;

	virtual ~ShareCompletedListener();

protected:
	ShareCompletedListener();

	bool init(ListenerID listenerId,
	std::function<void(ShareCompletedEvent*)> callback);

	std::function<void(ShareCompletedEvent*)> _onShareCompletedEvent;
};

#endif /* SHARECOMPLETEDLISTENER_H_ */
