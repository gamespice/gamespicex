#ifndef LEADERBOARD_H_
#define LEADERBOARD_H_

#include <string>
#include "../JSON.h"
#include <vector>

namespace gamespice {

class Score {
public:
	Score(int score);
	static Score fromJSON(JSON json);

	const int getScore();

	virtual ~Score();

private:
	int score;
};

class Leaderboard {
public:

	Leaderboard(const std::vector<Score> scores);

	static Leaderboard fromJSON(JSON json);

	const std::vector<Score> getScores();

	virtual ~Leaderboard();

private:

	std::string id_;std::vector<Score> scores;
};

} /* namespace gamespice */
#endif /* LEADERBOARD_H_ */
