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
		score(score) {
}

Score Score::fromJSON(JSON json) {
	Score score(json.getInt("score"));
	return score;
}

const int Score::getScore() {
	return score;
}

Score::~Score() {
}

} /* namespace gamespice */
