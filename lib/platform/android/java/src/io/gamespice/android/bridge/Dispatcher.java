package io.gamespice.android.bridge;

public class Dispatcher {

	public static void dispatch(String message) {
		Message m = Message.load(message);
		m.send();
	}
}
