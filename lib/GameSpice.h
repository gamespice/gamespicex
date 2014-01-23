#ifndef GAMESPICE_H_
#define GAMESPICE_H_

#include <string>

#include "cocos2d.h"
#include "models/User.h"
#include "APIClient.h"
#include "models/Leaderboard.h"
#include "models/Fund.h"
#include "models/InventoryItem.h"
#include "models/Order.h"
#include "models/Inventory.h"
#include "facebook/Facebook.h"

USING_NS_CC;
using namespace gamespice::facebook;
using namespace gamespice::android;
namespace gamespice {

class GameSpice: public cocos2d::CCObject {
public:

	const std::string API_ROOT = "http://gamespice.herokuapp.com";
//	const std::string API_ROOT = "http://10.0.2.2:9393";
	const std::string API_VERSION = "v1";

	const char* USER_KEY = "user_key";
	const char* GAME_KEY = "game_key";

	static GameSpice* getInstance();

	void init(const std::string gameId);

	void getUser(const std::string userId, std::function<void(User)> callback);
	void addUser(User user, std::function<void(User)> callback);
	void addFund(Fund fund, std::function<void(Fund)> callback);
	void getFund(std::function<void(Fund)> callback);
	void addScore(std::string leaderboardId, int score);
	void getHighScore(std::string leaderboardId,
	std::function<void(HighScore)> callback);
	void order(Order order);
	void getInventory(std::function<void(Inventory)> callback);
	void updateInventory(Inventory inventory);
	void getLeaderboard(std::string leaderboardId,
	std::function<void(Leaderboard)> callback);

	bool isCurrentPlayer(std::string userId);

	bool noRegisteredUser();

	virtual ~GameSpice();
private:

	void onGetUser(HttpClient *sender, HttpResponse *response);
	void onAddUser(HttpClient *sender, HttpResponse *response);
	void onAddFund(HttpClient *sender, HttpResponse *response);
	void onGetFund(HttpClient *sender, HttpResponse *response);
	void onGetInventory(HttpClient* sender, HttpResponse *response);
	void onGetHighScore(HttpClient* sender, HttpResponse *response);

	void onGetLeaderboard(HttpClient *sender, HttpResponse *response);

	bool isEmptyValue(const std::string key);

	std::string getUserId();

	std::string getGameId();

	JSON getJSONResponse(HttpResponse* response);

	std::function<void(User)> getUserCallback;std::function<void(Leaderboard)> getLeaderboardCallback;std::function<
			void(Fund)> getFundCallback;std::function<void(Inventory)> getInventoryCallback;std::function<
			void(User)> addUserCallback;std::function<void(Fund)> addFundCallback;std::function<
			void(HighScore)> getHighScoreCallback;
};

} /* namespace gamespice */
#endif /* GAMESPICE_H_ */
