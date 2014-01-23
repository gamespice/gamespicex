/*
 * Bundle.cpp
 *
 *  Created on: Jan 23, 2014
 *      Author: vini
 */

#include "Bundle.h"

namespace gamespice {
namespace android {

Bundle::Bundle() {

}

Bundle Bundle::add(std::string key, std::string value) {
	data[key] = Value(value);
	return *this;
}

Bundle Bundle::add(std::string key, int value) {
	data[key] = Value(value);
	return *this;
}

Bundle Bundle::add(std::string key, bool value) {
	data[key] = Value(value);
	return *this;
}

void Bundle::toJSON(json_t* jsonObject) {
	for (const auto& e : data) {
		const char* key = e.first.c_str();
		Value v = e.second;
		switch (v.getType()) {
		case Value::Type::STRING:
			json_object_set_new(jsonObject, key,
					json_string(v.asString().c_str()));
			break;
		case Value::Type::INTEGER:
			json_object_set_new(jsonObject, key, json_integer(v.asInt()));
			break;

		case Value::Type::BOOLEAN:
			json_object_set_new(jsonObject, key, json_boolean(v.asBool()));
			break;
		}
	}
}

Bundle::~Bundle() {
}

} /* namespace android */
} /* namespace gamespice */
