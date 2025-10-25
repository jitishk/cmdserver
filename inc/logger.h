#ifndef __LOGGER_H_
#define __LOGGER_H__

#include <iostream>

namespace jinfra::logger {

struct LOG {
	void operator()(const char* logStr) const {
		std::cout << logStr << std::endl;
	}
};

} // namespace jinfra::logger

#endif // __LOGGER_H__








