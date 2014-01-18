#ifndef USER_H_
#define USER_H_

#include <string>
#include "../JSON.h"

namespace gamespice {

class User {
public:

	User(const std::string name);

	static User fromJSON(JSON json);

	std::string toJSON();

	const std::string getName();
	const std::string getId();

	virtual ~User();

private:

	std::string id_;std::string name_;
};

} /* namespace gamespice */
#endif /* USER_H_ */
