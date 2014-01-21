/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 2.0.11
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package io.gamespice.android;

public class FacebookCallback {
  private long swigCPtr;
  protected boolean swigCMemOwn;

  protected FacebookCallback(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(FacebookCallback obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        gamespice_staticJNI.delete_FacebookCallback(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public FacebookCallback() {
    this(gamespice_staticJNI.new_FacebookCallback(), true);
  }

  public void onLogin() {
    gamespice_staticJNI.FacebookCallback_onLogin(swigCPtr, this);
  }

  public void onInviteFriendsComplete(vectorS friends, String invitedFriends) {
    gamespice_staticJNI.FacebookCallback_onInviteFriendsComplete(swigCPtr, this, vectorS.getCPtr(friends), friends, invitedFriends);
  }

  public void onShareComplete(String postId) {
    gamespice_staticJNI.FacebookCallback_onShareComplete(swigCPtr, this, postId);
  }

  public void onBragComplete(String postId) {
    gamespice_staticJNI.FacebookCallback_onBragComplete(swigCPtr, this, postId);
  }

}
