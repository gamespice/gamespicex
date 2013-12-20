#include "Fund.h"

namespace gamespice {

Fund::~Fund() {
}

Fund Fund::fromJSON(JSON json) {
	Fund fund(json.getInt("amount"));
	fund.id = json.getString("id");
	return fund;
}

std::string Fund::toJSON() {
	JSON json;
	json.addString("id", getId());
	json.addInt("amount", getAmount());
	return json.toString();
}

const int Fund::getAmount() {
	return amount;
}

Fund::Fund(int amount) :
		amount(amount) {
}

const std::string Fund::getId() {
	return id;
}

} /* namespace gamespice */
