#include "User.h"

namespace gamespice {

User::User(const std::string name) :
		name_(name) {
}

User User::fromJSON(JSON json) {
	User user(json.getString("name"));
	user.id_ = json.getString("id");
	return user;
}

const std::string User::getName() {
	return name_;
}

const std::string User::getId() {
	return id_;
}

std::string User::toJSON() {
	JSON json;
	json.addString("name", getName());
	return json.toString();
}

User::~User() {
}

} /* namespace gamespice */
