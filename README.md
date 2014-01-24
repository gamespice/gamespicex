GameSpiceX
==========

Game services client for cocos2d-x with Game Spice sweetness

# IMPORTANT

This is work in progress, it is not ready for use

## Features

Currently GameSpiceX supports the following features in cocos2d-x 3.0

* Login/Register User
* Post score to a Leaderboard
* Get Leaderboard
* Sell items
* Manage virtual currency (coins etc)
* Create Achievements

### Facebook integration

* Login
* Invite friends
* Share
* Brag
* Post score
* Unlock achievement

## How to install

Clone this repo into your cocos2d-x root

    git clone git@github.com:gamespice/gamespicex.git gamespice

Import Android project to Eclipse from ``lib/platform/android/java`` and make your project depend on it

Open your ``proj.android/jni/Android.mk`` file add this line at the end

    $(call import-module,gamespice) 

Add to LOCAL_WHOLE_STATIC_LIBRARIES

    gamespice_static

So it might look like this
    
    LOCAL_WHOLE_STATIC_LIBRARIES := cocos2dx_static cocosdenshion_static box2d_static gamespice_static

Add to your ``AndroidManifest.xml``

    <uses-permission android:name="android.permission.INTERNET" />

## How to use

#### Android/Java

Create custom application and override the onCreate method.
Include the facebook appId and appNamespace

```Java
@Override
public void onCreate() {
	super.onCreate();
	GameSpice.configure(<APP ID>, <APP NAMESPACE>);
}
```

Don't forget to include the app in the ``AndroidManifest.xml``

#### Cocos2d/C++

Include the Game Spice header file in your scene

```cpp
#include "GameSpice.h"
```

GameSpiceX uses the new event system introduced in Cocos2D 3.0 so everything uses the ```EventDispatcher```

How to login user via Facebook

```cpp
auto loggedInListener = EventListenerCustom::create(
	[=] (EventCustom* e) {
		auto event = (LoggedInEvent) e;
		CCLog("Logged in event");
	});
_eventDispatcher->addEventListenerWithFixedPriority(loggedInListener, 1);
Facebook::login();
```
