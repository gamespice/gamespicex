/*
 * BragCompletedListener.h
 *
 *  Created on: Jan 21, 2014
 *      Author: vini
 */

#ifndef BRAGCOMPLETEDLISTENER_H_
#define BRAGCOMPLETEDLISTENER_H_

#include "cocos2d.h"
#include "BragCompletedEvent.h"

USING_NS_CC;

class BragCompletedListener: public EventListener {
public:
	static BragCompletedListener* create(
	std::function<void(BragCompletedEvent*)> callback);

	virtual bool checkAvailable() override;
	virtual BragCompletedListener* clone() override;

	virtual ~BragCompletedListener();

protected:
	BragCompletedListener();

	bool init(ListenerID listenerId,
	std::function<void(BragCompletedEvent*)> callback);

	std::function<void(BragCompletedEvent*)> _onBragCompletedEvent;
};

#endif /* BRAGCOMPLETEDLISTENER_H_ */
