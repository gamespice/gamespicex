#include "Inventory.h"

namespace gamespice {

Inventory Inventory::fromJSON(JSON json) {
	Inventory inventory;
	auto itemsJSON = json.getArray("items");
	for (auto itemJSON : itemsJSON) {
		auto item = InventoryItem::fromJSON(itemJSON);
		inventory.items.insert(
				std::pair<std::string, InventoryItem>(item.getIdentifier(),
						item));
	}
	return inventory;
}

std::map<std::string, InventoryItem> Inventory::getItems() {
	return items;
}

std::string Inventory::toJSON() {
	JSON json;
	CCArray* itemsArray = CCArray::create();
	for (auto& itemPair : items) {
		itemsArray->addObject(CCString::create(itemPair.second.toJSON()));
	}
	json.addArray("items", itemsArray);
	return json.toString();
}

void Inventory::addItem(InventoryItem item) {
	items.insert(
			std::pair<std::string, InventoryItem>(item.getIdentifier(), item));
}

Inventory::~Inventory() {
}

} /* namespace gamespice */
