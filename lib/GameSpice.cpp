#include "GameSpice.h"

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
	APIClient::getInstance()->post("/users", user.toJSON());
}

GameSpice* GameSpice::getInstance() {
	if (!gameSpiceInstance) {
		gameSpiceInstance = new GameSpice();
		APIClient::getInstance()->configure(gameSpiceInstance->API_ROOT,
				gameSpiceInstance->API_VERSION);
	}
	return gameSpiceInstance;
}

void GameSpice::configure(const std::string gameId, const std::string userId) {
	this->gameId = gameId;
	this->userId = userId;
}

void GameSpice::getLeaderboard(std::string leaderboardId,
		std::function<void(Leaderboard)> callback) {
	this->getLeaderboardCallback = callback;
	std::string url = "/games/" + gameId + "/leaderboards/" + leaderboardId;
	APIClient::getInstance()->get(url.c_str(), this,
			httpresponse_selector(GameSpice::onGetLeaderboard));
		}

void GameSpice::onGetUser(CCHttpClient* sender, CCHttpResponse* response) {
	auto json = JSON::load(response->getResponseData());
	auto user = User::fromJSON(json);
	this->getUserCallback(user);
}

void GameSpice::onGetLeaderboard(CCHttpClient* sender,
		CCHttpResponse* response) {
	auto json = JSON::load(response->getResponseData());
	auto leaderboard = Leaderboard::fromJSON(json);
	this->getLeaderboardCallback(leaderboard);
}

} /* namespace gamespice */
