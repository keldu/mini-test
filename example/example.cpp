/**
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
*/
#include <keltest/test.h>

#include <string>

std::string greet(const std::string& val){
	return val;
}

namespace {
KEL_TEST("Greeting"){
	std::string hello = "hello";

	std::string answer = greet(hello);

	KEL_EXPECT(answer == "hello", "Person did not reply with a hello");
}

KEL_TEST("Weird Greeting"){
	std::string hello = "How are you?";

	std::string answer = greet(hello);

	KEL_EXPECT(answer == "Fine. How are you?", "Person did not reply with an expected answer");
}
}
