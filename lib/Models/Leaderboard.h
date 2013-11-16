#ifndef LEADERBOARD_H_
#define LEADERBOARD_H_

#include <string>
#include "../JSON.h"

namespace gamespice {

class Leaderboard {
public:

	Leaderboard(const std::string name);

	static Leaderboard fromJSON(JSON json);

	std::string toJSON();

	const std::string getName();

	virtual ~Leaderboard();

private:

	std::string id_;std::string name_;
};

} /* namespace gamespice */
#endif /* LEADERBOARD_H_ */
