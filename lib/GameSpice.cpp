#include "GameSpice.h"
#include "JSON.h"

namespace gamespice {

static GameSpice* gameSpiceInstance;

void GameSpice::getUser(std::string userId,
		std::function<void(User)> callback) {
	this->getUserCallback = callback;
	std::string url = "/users/" + userId;
	APIClient::getInstance()->get(url.c_str(), this,
			httpresponse_selector(GameSpice::onGetUser));
		}

GameSpice::~GameSpice() {
}

void GameSpice::addUser(User user) {
	APIClient::getInstance()->post("/users", user.toJSON(), this,
			httpresponse_selector(GameSpice::onAddUser));
		}

GameSpice* GameSpice::getInstance() {
	if (!gameSpiceInstance) {
		gameSpiceInstance = new GameSpice();
		APIClient::getInstance()->configure(gameSpiceInstance->API_ROOT,
				gameSpiceInstance->API_VERSION);
	}
	return gameSpiceInstance;
}

void GameSpice::getLeaderboard(std::string leaderboardId,
		std::function<void(Leaderboard)> callback) {
	this->getLeaderboardCallback = callback;
	std::string url = "/games/" + getGameId() + "/leaderboards/" + leaderboardId
			+ "/scores/" + getUserId();
	APIClient::getInstance()->get(url.c_str(), this,
			httpresponse_selector(GameSpice::onGetLeaderboard));
		}

void GameSpice::onGetUser(CCHttpClient* sender, CCHttpResponse* response) {
	auto user = User::fromJSON(getJSONResponse(response));
	this->getUserCallback(user);
}

void GameSpice::onAddUser(CCHttpClient* sender, CCHttpResponse* response) {
	auto user = User::fromJSON(getJSONResponse(response));
	auto db = CCUserDefault::sharedUserDefault();
	db->setStringForKey(USER_KEY.c_str(), user.getId());
	db->flush();
}

bool GameSpice::noRegisteredUser() {
	return isEmptyValue(USER_KEY);
}

void GameSpice::init(const std::string gameId) {
	if (isEmptyValue(GAME_KEY)) {
		auto db = CCUserDefault::sharedUserDefault();
		db->setStringForKey(GAME_KEY.c_str(), gameId);
		db->flush();
	}
}

void GameSpice::onGetLeaderboard(CCHttpClient* sender,
		CCHttpResponse* response) {
	auto leaderboard = Leaderboard::fromJSON(getJSONResponse(response));
	this->getLeaderboardCallback(leaderboard);
}

void GameSpice::addFund(Fund fund) {
	std::string url = "/games/" + getGameId() + "/funds/" + getUserId();
	APIClient::getInstance()->post(url.c_str(), fund.toJSON());
}

void GameSpice::getFund(std::function<void(Fund)> callback) {
	this->getFundCallback = callback;
	std::string url = "/games/" + getGameId() + "/funds/" + getUserId();
	APIClient::getInstance()->get(url.c_str(), this,
			httpresponse_selector(GameSpice::onGetFund));
		}

bool GameSpice::isEmptyValue(const std::string key) {
	auto db = CCUserDefault::sharedUserDefault();
	auto emptyString = std::string("");
	auto value = db->getStringForKey(key.c_str(), emptyString);
	return value.empty();
}

std::string GameSpice::getGameId() {
	auto db = CCUserDefault::sharedUserDefault();
	return db->getStringForKey(GAME_KEY.c_str());
}

std::string GameSpice::getUserId() {
	auto db = CCUserDefault::sharedUserDefault();
	return db->getStringForKey(USER_KEY.c_str());
}

void GameSpice::onGetFund(CCHttpClient* sender, CCHttpResponse* response) {
	auto fund = Fund::fromJSON(getJSONResponse(response));
	this->getFundCallback(fund);
}

void GameSpice::addScore(std::string leaderboardId, int score) {
	JSON json;
	json.addInt("score", score);
	std::string url = "/games/" + getGameId() + "/leaderboards/" + leaderboardId
			+ "/scores/" + getUserId();
	APIClient::getInstance()->post(url.c_str(), json.toString());
}

void GameSpice::order(Order order) {
	std::string url = "/games/" + getGameId() + "/items/" + getUserId()
			+ "/order";
	APIClient::getInstance()->put(url.c_str(), order.toJSON());
}

void GameSpice::getInventory(std::function<void(Inventory)> callback) {
	std::string url = "/games/" + getGameId() + "/items/" + getUserId();
	this->getInventoryCallback = callback;
	APIClient::getInstance()->get(url.c_str(), this,
			httpresponse_selector(GameSpice::onGetInventory));
		}

void GameSpice::updateInventory(Inventory inventory) {
	std::string url = "/games/" + getGameId() + "/items/" + getUserId();
	APIClient::getInstance()->put(url.c_str(), inventory.toJSON());
}

void GameSpice::onGetInventory(CCHttpClient* sender, CCHttpResponse* response) {
	auto inventory = Inventory::fromJSON(getJSONResponse(response));
	this->getInventoryCallback(inventory);
}

JSON GameSpice::getJSONResponse(CCHttpResponse* response) {
	return JSON::load(response->getResponseData());

}

} /* namespace gamespice */
