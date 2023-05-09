#pragma once

#include <string>
#include <stdexcept>

namespace keltest {
class test_runner;
class test_case {
private:
	std::string file;
	uint32_t line;
	std::string description;
	test_case* next;
	test_case** prev;
public:
	test_case(std::string file_, uint32_t line_, std::string description_);
	~test_case();

	virtual void run() = 0;
};
}
#include "macro.h"
