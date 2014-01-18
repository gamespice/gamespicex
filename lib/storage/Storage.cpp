#include "Storage.h"

namespace gamespice {

Storage::Storage() {
	storable = new LocalStorage;
}

Storage::~Storage() {
	delete storable;
}

} /* namespace gamespice */
