#ifndef GAMESPICE_H_
#define GAMESPICE_H_

#include <string>

#include "cocos-ext.h"
#include "cocos2d.h"
#include "Models/User.h"
#include "APIClient.h"
#include "Models/Leaderboard.h"

using namespace cocos2d::extension;
USING_NS_CC;
namespace gamespice {

class GameSpice: public cocos2d::CCObject {
public:

	const std::string API_ROOT = "SET API ROOT HERE";
	const std::string API_VERSION = "v1";

	static GameSpice* getInstance();

	void configure(const std::string gameId, const std::string userId);

	void getUser(std::string userId, std::function<void(User)> callback);
	void addUser(User user);

	void getLeaderboard(std::string leaderboardId, std::function<void(Leaderboard)> callback);

	virtual ~GameSpice();
private:

	void onGetUser(CCHttpClient *sender, CCHttpResponse *response);

	void onGetLeaderboard(CCHttpClient *sender, CCHttpResponse *response);

	std::function<void(User)> getUserCallback;
	std::function<void(Leaderboard)> getLeaderboardCallback;

	std::string gameId;std::string userId;
};

} /* namespace gamespice */
#endif /* GAMESPICE_H_ */
