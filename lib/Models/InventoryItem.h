#ifndef ITEM_H_
#define ITEM_H_

#include <string>
#include "../JSON.h"

namespace gamespice {

class InventoryItem {
public:

	InventoryItem(std::string identifier, int quantity);

	static InventoryItem fromJSON(JSON json);

	std::string toJSON();

	const std::string getIdentifier() const;

	const std::string getName() const;

	int getQuantity() const;

	virtual ~InventoryItem();

private:
	std::string name;std::string identifier;
	int quantity;
};

} /* namespace gamespice */
#endif /* ITEM_H_ */
