#ifndef INVENTORY_H_
#define INVENTORY_H_

#include "../JSON.h"
#include "InventoryItem.h"
#include <map>
#include <string>

namespace gamespice {

class Inventory {
public:

	static Inventory fromJSON(JSON json);

	void addItem(InventoryItem item);

	std::string toJSON();

	std::map<std::string, InventoryItem> getItems();

	virtual ~Inventory();

private:
	std::map<std::string, InventoryItem> items;
};

} /* namespace gamespice */
#endif /* INVENTORY_H_ */
