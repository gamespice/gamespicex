/*
 * ShareDTO.h
 *
 *  Created on: Jan 23, 2014
 *      Author: vini
 */

#ifndef SHAREDTO_H_
#define SHAREDTO_H_
#include "../Bundle.h"

namespace gamespice {
namespace android {

class ShareDTO {
public:
	ShareDTO(std::string message, std::string name, std::string link,
			std::string description);

	Bundle toBundle();

	virtual ~ShareDTO();

	std::string message;
	std::string name;
	std::string link;
	std::string description;
};

} /* namespace android */
} /* namespace gamespice */

#endif /* SHAREDTO_H_ */
