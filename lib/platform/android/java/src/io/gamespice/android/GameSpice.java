package io.gamespice.android;

import java.util.List;

import org.cocos2dx.lib.Cocos2dxHelper;

import android.app.Activity;
import android.content.Intent;

import com.sromku.simple.fb.SimpleFacebook;
import com.sromku.simple.fb.SimpleFacebook.OnInviteListener;
import com.sromku.simple.fb.SimpleFacebook.OnLoginListener;

public class GameSpice {

	private static SimpleFacebook facebook;
	private static Activity activity;

	public GameSpice(Activity activity) {
		GameSpice.activity = activity;
		facebook = SimpleFacebook.getInstance(activity);
	}

	public void onActivityResult(Activity activity, int requestCode,
			int resultCode, Intent data) {
		facebook.onActivityResult(activity, requestCode, resultCode, data);
	}

	public void onResume(Activity activity) {
		facebook = SimpleFacebook.getInstance(activity);
		GameSpice.activity = activity;
	}

	public static void login() {
		activity.runOnUiThread(new Runnable() {

			@Override
			public void run() {
				if (!facebook.isLogin()) {
					facebook.login(new OnLoginListener() {

						@Override
						public void onFail(String reason) {

						}

						@Override
						public void onException(Throwable throwable) {

						}

						@Override
						public void onThinking() {

						}

						@Override
						public void onNotAcceptingPermissions() {

						}

						@Override
						public void onLogin() {
							callOnLoginCallback();
						}
					});
				} else {
					callOnLoginCallback();
				}
			}

		});
	}

	private static void callOnLoginCallback() {
		Cocos2dxHelper.runOnGLThread(new Runnable() {

			@Override
			public void run() {
				FacebookCallback callback = new FacebookCallback();
				callback.onLogin();
			}
		});
	}

	public static void inviteFriends(final String message) {

		activity.runOnUiThread(new Runnable() {

			@Override
			public void run() {
				facebook.login(new OnLoginListener() {

					@Override
					public void onFail(String reason) {

					}

					@Override
					public void onException(Throwable throwable) {

					}

					@Override
					public void onThinking() {

					}

					@Override
					public void onNotAcceptingPermissions() {

					}

					@Override
					public void onLogin() {
						facebook.invite(message, new OnInviteListener() {

							@Override
							public void onFail(String reason) {

							}

							@Override
							public void onException(Throwable throwable) {

							}

							@Override
							public void onComplete(
									final List<String> invitedFriends,
									final String requestId) {

								Cocos2dxHelper.runOnGLThread(new Runnable() {

									@Override
									public void run() {
										FacebookCallback callback = new FacebookCallback();
										vectorS v = new vectorS();
										for (String friend : invitedFriends) {
											v.add(friend);
										}
										callback.onInviteFriendsComplete(v,
												requestId);
									}
								});

							}

							@Override
							public void onCancel() {

							}
						});
					}
				});

			}
		});

	}

}
