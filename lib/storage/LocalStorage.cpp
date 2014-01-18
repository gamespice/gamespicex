#include "LocalStorage.h"

namespace gamespice {

void LocalStorage::saveFund(Fund fund) {
	db->setStringForKey(FUND_KEY.c_str(), fund.toJSON());
	db->flush();
}

Fund LocalStorage::getFund() {
	auto fundJSON = db->getStringForKey(FUND_KEY.c_str());
	return Fund::fromJSON(fundJSON);
}

LocalStorage::~LocalStorage() {
}

} /* namespace gamespice */
