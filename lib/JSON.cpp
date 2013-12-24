#include "JSON.h"
#include "json/CCJSONConverter.h"

namespace gamespice {

JSON JSON::load(std::vector<char>* buffer) {
	std::string data;
	for (unsigned int i = 0; i < buffer->size(); i++) {
		data += (*buffer)[i];
	}
	auto dataString = data.c_str();
	char dataBuffer[sizeof(dataString) * data.size()];
	memcpy(dataBuffer, dataString, sizeof(dataString) * data.size());
	return JSON(dataBuffer);
}

JSON::JSON(char* data) {
	jsonDic = CCJSONConverter::sharedConverter()->dictionaryFrom(data);
	jsonDic->retain();
}

JSON::JSON(CCDictionary* dict) {
	jsonDic = dict;
	jsonDic->retain();
}

JSON::JSON(): JSON(CCDictionary::create()) {

}

std::string JSON::getString(const char* key) {
	auto string = (CCString*) jsonDic->objectForKey(key);
	return string->m_sString;
}

int JSON::getInt(const char* key) {
	auto integer = (CCInteger*) jsonDic->objectForKey(key);
	return integer->getValue();
}

void JSON::addString(const char* key, const std::string& value) {
	jsonDic->setObject(CCString::create(value), key);
}

void JSON::addInt(const char* key, int value) {
	jsonDic->setObject(CCNumber::create(value), key);
}

void JSON::addArray(const char* key, CCArray* array) {
	jsonDic->setObject(array, key);
}

std::string JSON::toString() {
	auto converter = CCJSONConverter::sharedConverter();
	return std::string(converter->strFrom(jsonDic));
}

std::vector<JSON> JSON::getArray(const char* key) {
	std::vector<JSON> result;
	auto array = (CCArray*) jsonDic->objectForKey(key);
	CCObject* obj;
	CCARRAY_FOREACH(array, obj) {
		auto itemDict = (CCDictionary*) obj;
		auto jsonItem = JSON(
				CCJSONConverter::sharedConverter()->strFrom(itemDict));
		result.push_back(jsonItem);
	}
	return result;
}

JSON::~JSON() {
}

} /* namespace gamespice */
