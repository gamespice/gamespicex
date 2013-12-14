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
	const int getPlace();
	const std::string getUsername();
	const std::string getUserId();


	virtual ~Score();

private:
	int score;std::string userId;
	int place;std::string username;
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
