#ifndef STORAGE_H_
#define STORAGE_H_
#include "Storable.h"
#include <vector>

namespace gamespice {

class Storage {
public:

	Storage();

	virtual ~Storage();
private:

	Storable* storable;
};

} /* namespace gamespice */
#endif /* STORAGE_H_ */
