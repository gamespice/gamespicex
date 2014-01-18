#ifndef ORDER_H_
#define ORDER_H_

#include "../JSON.h"
#include "InventoryItem.h"
#include <vector>
#include <string>

USING_NS_CC;

namespace gamespice {

class Order {
public:

	void addItem(InventoryItem item);

	std::string toJSON();

	virtual ~Order();
private:
	std::vector<InventoryItem> items;
};

} /* namespace gamespice */
#endif /* ORDER_H_ */
