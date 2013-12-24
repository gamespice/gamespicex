#include "InventoryItem.h"

namespace gamespice {

InventoryItem::InventoryItem(std::string identifier, int quantity) :
		identifier(identifier), quantity(quantity), name("") {
}

const std::string InventoryItem::getIdentifier() const {
	return identifier;
}

const std::string InventoryItem::getName() const {
	return name;
}

int InventoryItem::getQuantity() const {
	return quantity;
}

InventoryItem InventoryItem::fromJSON(JSON json) {
	InventoryItem item(json.getString("identifier"), json.getInt("quantity"));
	item.name = json.getString("name");
	return item;
}

std::string InventoryItem::toJSON() {
	return JSON(toDict()).toString();
}

CCDictionary* InventoryItem::toDict() {
	auto dic = CCDictionary::create();
	dic->setObject(CCString::create(getIdentifier()), "identifier");
	dic->setObject(CCNumber::create(getQuantity()), "quantity");
	return dic;
}

InventoryItem::~InventoryItem() {
}

} /* namespace gamespice */
