package io.gamespice.android;

import android.app.NativeActivity;
import android.content.Intent;
import android.os.Bundle;

public class GameSpiceActivity extends NativeActivity {

	private GameSpice gameSpice;

	// private SimpleFacebook facebook;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		gameSpice = new GameSpice(this);
		// facebook = SimpleFacebook.getInstance(this);

		// runOnUiThread(new Runnable() {
		//
		// @Override
		// public void run() {
		// facebook.login(new OnLoginListener() {
		//
		// @Override
		// public void onFail(String reason) {
		// // TODO Auto-generated method stub
		//
		// }
		//
		// @Override
		// public void onException(Throwable throwable) {
		// // TODO Auto-generated method stub
		//
		// }
		//
		// @Override
		// public void onThinking() {
		// // TODO Auto-generated method stub
		//
		// }
		//
		// @Override
		// public void onNotAcceptingPermissions() {
		// // TODO Auto-generated method stub
		//
		// }
		//
		// @Override
		// public void onLogin() {
		// Log.d("InviteFriends", "Invite friends called");
		// facebook.invite("Hello", new OnInviteListener() {
		//
		// @Override
		// public void onFail(String reason) {
		//
		// }
		//
		// @Override
		// public void onException(Throwable throwable) {
		//
		// }
		//
		// @Override
		// public void onComplete(List<String> invitedFriends,
		// String requestId) {
		// Log.d("FriendsInvited", "Friends were invated");
		// FacebookCallback callback = new FacebookCallback();
		// vectorS v = new vectorS();
		// for (String friend : invitedFriends) {
		// v.add(friend);
		// }
		// callback.onInviteFriendsComplete(v, requestId);
		// callback.delete();
		// }
		//
		// @Override
		// public void onCancel() {
		//
		// }
		// });
		// }
		// });
		//
		// }
		// });
	}

	@Override
	protected void onResume() {
		super.onResume();
		gameSpice.onResume(this);
		// facebook = SimpleFacebook.getInstance(this);
	}

	@Override
	protected void onActivityResult(int requestCode, int resultCode, Intent data) {
		// facebook.onActivityResult(this, requestCode, resultCode, data);
		gameSpice.onActivityResult(this, requestCode, resultCode, data);
		super.onActivityResult(requestCode, resultCode, data);
	}
}
