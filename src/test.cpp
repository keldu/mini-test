#include "test.h"

#include <chrono>
#include <iostream>
namespace keltest {

template<typename... T>
constexpr bool always_false = false;

test_case* test_case_head = nullptr;
test_case** test_case_tail = &test_case_head;

test_case::test_case(std::string file_, uint32_t line_, std::string& description_):
	file{std::move(file_)},
	line{line_},
	description{std::move(description_)},
	next{nullptr},
	prev{test_case_tail}
{
	/**
	 * Since I always forget how this works.
	 */
	/**
	 * If the list is empty, then this command sets the head to this
	 * If the list is not empty it sets the previous test_case "next" to this location
	 */
	*prev = this;
	/**
	 * The tail is set this->next location which is used in a later test_case's constructor
	 */
	test_case_tail = &next;
}

test_case::~test_case(){
	*prev = next;
	if( next == nullptr ){
		test_case_tail = prev;
	}else {
		next->prev = prev;
	}
}

namespace colour {
struct red {};
struct green {};
struct blue {};
struct white {};

using variant = std::variant<white, red, green, blue>;
}


class test_runner {
private:
	void write(const colour::variant& col, const std::string& front, const std::string& message){
		std::string_view start_col, end_col;
		start_col = std::visit([](auto& col) -> std::string_view {
			using T = std::decay_t<decltype(col)>;

			if constexpr ( std::is_same_v<T, colour::red> ){
				return "\033[0;1;31m";
			}
			else if constexpr ( std::is_same_v<T, colour::green> ){
				return "\033[0;1;32m";
			}
			else if constexpr ( std::is_same_v<T, colour::blue> ){
				return "\033[0;1;34m";
			}
			else if constexpr ( std::is_same_v<T, colour::white> ){
				return "\033[0m";
			}
			else {
				static_assert(always_false<T>, "Case exhausted");
			}
			return "\033[0m";
		}, col);
		end_col = "\033[0m";

		std::cout<<start_col<<front<<end_col<<message<<'\n';
	}
public:

	int run() {
		size_t passed_count = 0;
		size_t failed_count = 0;

		for(test_case* test = test_case_head; test != nullptr; test = test->next){
			std::string name = test->fil + std::string{":"} + std::to_string(test->line) + std::string{":"} + test->description;
			write(colour::blue, "[ TEST ] ", name);
			bool failed = true;

			std::string fail_message;
			auto start_clock = std::chrono::steady_clock::now();

			try {
				test->run();
				failed = false;
			}catch(std::exception& e){
				fail_message = e.what();
				failed = true;
			}
			auto stop_clock = std::chrono::steady_clock::now();

			auto runtime_duration_intern = stop_clock - start_clock;

			auto runtime_duration = std::chrono::duration_cast<std::chrono::microseconds>(runtime_duration_intern);

			std::string message = name + std::string{" ("} + std::to_string(runtime_duration.count()) + std::string{" µs) "};
			
			if( failed ){
				write(colour::red, "[ FAIL ] ", message + std::string{" "} + fail_message);
				++failed_count;
			}else{
				write(colour::green, "[ PASS ] ", message);
				++passed_count;
			}
		}

		if( passed_count > 0 ) write(colour::green, std::to_string(passed_count) + std::string{" test(s) passed"}, "");

		if( failed_count > 0 ) write(colour::red, std::to_string(failed_count) + std::string{" test(s) failed"}, "");

		return failed_count > 0 ? -1 : 0;
	}
};
}

#if KELTEST_COMPILE_TEST_BINARY

int main() {
	::keltest::test_runner runner;
	int rv = runner.run();

	return rv != 0 ? -1 : 0;
}

#endif
