Copyright (C) 2023  Claudius "keldu" Holeksa

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU Affero General Public License as
published by the Free Software Foundation, either version 3 of the
License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Affero General Public License for more details.

You should have received a copy of the GNU Affero General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.

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

	friend class test_runner;
public:
	test_case(std::string file_, uint32_t line_, std::string description_);
	~test_case();

	virtual void run() = 0;
};
}
#include "macro.h"
