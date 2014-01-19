package io.gamespice.android;

import android.app.NativeActivity;
import android.content.Intent;
import android.os.Bundle;

public class GameSpiceActivity extends NativeActivity {

	private GameSpice gameSpice;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		gameSpice = new GameSpice(this);
	}

	@Override
	protected void onResume() {
		super.onResume();
		gameSpice.onResume(this);
	}

	@Override
	protected void onActivityResult(int requestCode, int resultCode, Intent data) {
		gameSpice.onActivityResult(this, requestCode, resultCode, data);
		super.onActivityResult(requestCode, resultCode, data);
	}
}
