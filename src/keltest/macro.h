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

#define KEL_CONCAT_(x, y) x##y
#define KEL_CONCAT(x, y) KEL_CONCAT_(x, y)

#define KEL_UNIQUE_NAME(prefix) KEL_CONCAT(prefix, __LINE__)

#define KEL_TEST(description) \
	class KEL_UNIQUE_NAME(test_case) : public ::keltest::test_case { \
		public: \
			KEL_UNIQUE_NAME(test_case)(): ::keltest::test_case(__FILE__,__LINE__,description) {} \
		void run() override; \
	} KEL_UNIQUE_NAME(test_case_); \
	void KEL_UNIQUE_NAME(test_case)::run()

#define KEL_EXPECT(expr, msg_split) \
		if( ! (expr) ){ \
			auto msg = msg_split; \
			throw std::runtime_error{std::string{msg}}; \
		}
