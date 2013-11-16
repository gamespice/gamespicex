#include "Leaderboard.h"

namespace gamespice {

Leaderboard::Leaderboard(const std::string name) :
		name_(name) {
}

Leaderboard Leaderboard::fromJSON(JSON json) {
	Leaderboard leaderboard(json.getString("name"));
	leaderboard.id_ = json.getString("id");
	return leaderboard;
}

std::string Leaderboard::toJSON() {
	JSON json;
	json.addString("name", getName());
	return json.toString();
}

const std::string Leaderboard::getName() {
	return name_;
}

Leaderboard::~Leaderboard() {
}

} /* namespace gamespice */
