#include "Fund.h"

namespace gamespice {

Fund::~Fund() {
}

Fund Fund::fromJSON(JSON json) {
	Fund fund;
	fund.id = json.getString("id");
	fund.amount = json.getInt("amount");
	return fund;
}

std::string Fund::toJSON() {
	JSON json;
	json.addString("amount", getAmount());
	return json.toString();
}

const std::string Fund::getAmount() {
	return amount;
}

Fund::Fund(int amount) :
		amount(amount) {
}

const std::string Fund::getId() {
	return id_;
}

} /* namespace gamespice */
