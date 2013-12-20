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
	JSON json;
	json.addString("identifier", getIdentifier());
	json.addInt("quantity", getQuantity());
	return json.toString();
}

InventoryItem::~InventoryItem() {
}

} /* namespace gamespice */
