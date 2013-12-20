#ifndef JSONPARSER_H_
#define JSONPARSER_H_

#include <vector>
#include <string>

#include "cocos2d.h"

USING_NS_CC;

namespace gamespice {

class JSON {
public:

	JSON(char* data);
	JSON();

	static JSON load(std::vector<char> *data);

	std::string getString(const char* key);

	int getInt(const char* key);

	std::vector<JSON> getArray(const char* key);

	void addString(const char* key, const std::string& value);
	void addInt(const char* key, int value);
	void addArray(const char* key, CCArray* array);

	std::string toString();

	virtual ~JSON();

private:

	CCDictionary* jsonDic;
//	Document document;
};

} /* namespace gamespice */
#endif /* JSONPARSER_H_ */
