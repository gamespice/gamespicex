/*
 * ShareDTO.cpp
 *
 *  Created on: Jan 23, 2014
 *      Author: vini
 */

#include "ShareDTO.h"

namespace gamespice {
namespace android {

ShareDTO::ShareDTO(std::string message, std::string name,
std::string description, std::string link) :
		message(message), name(name), link(link), description(description) {

}

Bundle ShareDTO::toBundle() {
	return Bundle().add(std::string("message"), message).add(
	std::string("name"), name).add(
	std::string("link"), link).add(std::string("description"), description);

}

ShareDTO::~ShareDTO() {
}

} /* namespace android */
} /* namespace gamespice */
