#include "Leaderboard.h"

namespace gamespice {

Leaderboard::Leaderboard(const std::vector<Score> scores) :
		scores(scores) {
}

Leaderboard Leaderboard::fromJSON(JSON json) {
	auto scoresJSON = json.getArray("scores");
	std::vector<Score> scores;
	for (auto scoreJSON : scoresJSON) {
		scores.push_back(Score::fromJSON(scoreJSON));
	}
	Leaderboard leaderboard(scores);
	return leaderboard;
}

const std::vector<Score> Leaderboard::getScores() {
	return scores;
}

Leaderboard::~Leaderboard() {
}

Score::Score(int score) :
		score(score), place(0) {
}

Score Score::fromJSON(JSON json) {
	Score score(json.getInt("score"));
	score.place = json.getInt("place");
	score.username = json.getString("username");
	score.userId = json.getString("user_id");
	return score;
}

const int Score::getScore() {
	return score;
}

const int Score::getPlace() {
	return place;
}

const std::string Score::getUsername() {
	return username;
}

const std::string Score::getUserId() {
	return userId;
}

Score::~Score() {
}

} /* namespace gamespice */
