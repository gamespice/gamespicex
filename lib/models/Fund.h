#ifndef FUND_H_
#define FUND_H_

#include <string>
#include "../JSON.h"

namespace gamespice {

class Fund {
public:
	virtual ~Fund();

	Fund(int amount);

	static Fund fromJSON(JSON json);

	std::string toJSON();

	const int getAmount();
	const std::string getId();

private:

	std::string id;
	int amount;
};

} /* namespace gamespice */
#endif /* FUND_H_ */
