#ifndef GAMESPICE_H_
#define GAMESPICE_H_

#include <string>

#include "cocos-ext.h"
#include "cocos2d.h"
#include "Models/User.h"
#include "APIClient.h"
#include "Models/Leaderboard.h"
#include "Models/Fund.h"
#include "Models/InventoryItem.h"
#include "Models/Order.h"
#include "Models/Inventory.h"

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
	void addFund(Fund fund);
	void getFund(std::function<void(Fund)> callback);
	void addScore(std::string leaderboardId, int score);
	void order(Order order);
	void getInventory(std::function<void(Inventory)> callback);
	void updateInventory(Inventory inventory);
	void getLeaderboard(std::string leaderboardId,
			std::function<void(Leaderboard)> callback);

	bool noRegisteredUser();

	virtual ~GameSpice();
private:

	void onGetUser(CCHttpClient *sender, CCHttpResponse *response);
	void onAddUser(CCHttpClient *sender, CCHttpResponse *response);
	void onGetFund(CCHttpClient *sender, CCHttpResponse *response);
	void onGetInventory(CCHttpClient* sender, CCHttpResponse *response);

	void onGetLeaderboard(CCHttpClient *sender, CCHttpResponse *response);

	bool isEmptyValue(const std::string key);

	std::string getUserId();

	std::string getGameId();

	JSON getJSONResponse(CCHttpResponse* response);

	std::function<void(User)> getUserCallback;std::function<void(Leaderboard)> getLeaderboardCallback;std::function<
			void(Fund)> getFundCallback; std::function<void(Inventory)> getInventoryCallback;

};

} /* namespace gamespice */
#endif /* GAMESPICE_H_ */
