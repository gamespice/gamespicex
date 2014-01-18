GameSpiceX
==========

Game services client for cocos2d-x with GameSpice sweetness

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

* Invite friends

## How to install

Clone this repo into your cocos2d-x root

    git clone git@github.com:gamespice/gamespicex.git gamespice

Open your ``proj.android/jni/Android.mk`` file add this line at the end

    $(call import-module,gamespice) 

Add to LOCAL_WHOLE_STATIC_LIBRARIES

    gamespice_static

So it might look like this
    
    LOCAL_WHOLE_STATIC_LIBRARIES := cocos2dx_static cocosdenshion_static box2d_static gamespice_static

Add to your ``AndroidManifest.xml``

    <uses-permission android:name="android.permission.INTERNET" />
