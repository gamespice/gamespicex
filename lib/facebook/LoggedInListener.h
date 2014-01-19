/*
 * LoggedInListener.h
 *
 *  Created on: Jan 19, 2014
 *      Author: vini
 */

#ifndef LOGGEDINLISTENER_H_
#define LOGGEDINLISTENER_H_

#include "cocos2d.h"
#include "LoggedInEvent.h"

USING_NS_CC;
class LoggedInListener: public EventListener {
public:

	static LoggedInListener* create(
	std::function<void(LoggedInEvent*)> callback);

	virtual bool checkAvailable() override;
	virtual LoggedInListener* clone() override;

	virtual ~LoggedInListener();

protected:
	LoggedInListener();

	bool init(ListenerID listenerId,
	std::function<void(LoggedInEvent*)> callback);

	std::function<void(LoggedInEvent*)> _onLoggedInEvent;
};

#endif /* LOGGEDINLISTENER_H_ */
