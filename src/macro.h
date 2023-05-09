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
