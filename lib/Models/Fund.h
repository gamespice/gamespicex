#ifndef FUND_H_
#define FUND_H_

namespace gamespice {

class Fund {
public:
	virtual ~Fund();

	Fund(int amount);

	static Fund fromJSON(JSON json);

	std::string toJSON();

	const std::string getAmount();
	const std::string getId();

private:

	std::string id;
	int amount;
};

} /* namespace gamespice */
#endif /* FUND_H_ */
