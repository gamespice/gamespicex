package io.gamespice.android;

import java.lang.reflect.Method;

import org.json.JSONException;
import org.json.JSONObject;

import com.google.gson.Gson;

public class Message {

	private JSONObject message;

	public Message(JSONObject message) {
		this.message = message;
	}

	public static Message load(String message) {
		try {
			JSONObject json = new JSONObject(message);
			return new Message(json);
		} catch (JSONException e) {
			throw new GameSpiceException("Invalid message JSON string");
		}

	}

	void send() {
		Method method = getMethod();
		Class<?>[] parameters = method.getParameterTypes();
		if (parameters.length != 1) {
			throw new GameSpiceException(
					"Did you forget to add argument to the action method? Action method must have exactly 1 argument.");
		}
		Class<?> paramClass = parameters[0];

		Gson gson = new Gson();
		Object object;
		try {
			object = gson.fromJson(message.getJSONObject("data").toString(),
					paramClass);

		} catch (Exception e) {
			throw new GameSpiceException(
					"Did you forget to add the data to the JSON object?");
		}
		try {
			method.invoke(null, object);
		} catch (Exception e) {
			throw new GameSpiceException("Unable to call the action method");
		}
	}

	private Method getMethod() {
		String action;
		try {
			action = message.getString("action");
		} catch (JSONException e) {
			throw new GameSpiceException(
					"Did you forget to add the action to the JSON object?");
		}
		Method[] methods = GameSpice.class.getMethods();
		for (Method m : methods) {
			if (m.getName().equals(action)) {
				return m;
			}
		}
		throw new GameSpiceException("Action " + action
				+ " is not defined in GameSpice");
	}
}
