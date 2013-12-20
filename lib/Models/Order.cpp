#include "Order.h"

namespace gamespice {

void Order::addItem(InventoryItem item) {
	items.push_back(item);
}

std::string Order::toJSON() {
	JSON json;
	CCArray* itemsArray = CCArray::create();
	for (auto item : items) {
		itemsArray->addObject(CCString::create(item.toJSON()));
	}
	json.addArray("items", itemsArray);
	return json.toString();
}

Order::~Order() {
}

} /* namespace gamespice */
