#ifndef STORAGE_H_
#define STORAGE_H_
#include "../Models/Fund.h"

namespace gamespice {

class Storable {
public:


	virtual void saveFund(Fund) = 0;
	virtual Fund getFund() = 0;

	virtual ~Storable() {}
};

} /* namespace gamespice */
#endif /* STORABLE_H_ */
