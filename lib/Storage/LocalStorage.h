#ifndef LOCALSTORAGE_H_
#define LOCALSTORAGE_H_
#include "Storable.h"

namespace gamespice {

class LocalStorage: public Storable {
public:

	LocalStorage() : db(CCUserDefault::sharedUserDefault()) {}

	void saveFund(Fund) override;
	Fund getFund() override;

	virtual ~LocalStorage();
private:

	const std::string FUND_KEY = "fund_key";

	CCUserDefault* db;
};

} /* namespace gamespice */
#endif /* LOCALSTORAGE_H_ */
