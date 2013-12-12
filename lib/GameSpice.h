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

	const std::string API_ROOT = "http://10.0.2.2:9393";
	const std::string API_VERSION = "v1";

	const std::string USER_KEY = "user_key";
	const std::string GAME_KEY = "game_key";

	static GameSpice* getInstance();

	void init(const std::string gameId);

	void getUser(const std::string userId, std::function<void(User)> callback);
	void addUser(User user);
	void addFunds(Fund fund);
	void getFund(std::function<void(Fund)> callback);

	bool noRegisteredUser();

	void getLeaderboard(std::string leaderboardId,
			std::function<void(Leaderboard)> callback);

	virtual ~GameSpice();
private:

	void onGetUser(CCHttpClient *sender, CCHttpResponse *response);
	void onAddUser(CCHttpClient *sender, CCHttpResponse *response);
	void onGetFund(CCHttpClient *sender, CCHttpResponse *response);

	void onGetLeaderboard(CCHttpClient *sender, CCHttpResponse *response);

	bool isEmptyValue(const std::string key);

	std::string getGameId();
	std::string getUserId();

	JSON getJSONResponse(CCHttpResponse* response);

	std::function<void(User)> getUserCallback;
	std::function<void(Leaderboard)> getLeaderboardCallback;
	std::function<void(Fund)> getFundCallback;

};

} /* namespace gamespice */
#endif /* GAMESPICE_H_ */
