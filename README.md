# keldu's minimal testing framework  

I jokingly suggested using my mini framework which is baked in a private repo for a project.  
Though I didn't seriously suggest it, some attendants wanted me to at least make it
available to the public.  
So here we are.  

This works similarly to other test frameworks, but with minimality in mind.  

# Building
## The project itself  

### Dependencies  

* c++ compiler (c++17) (Usually clang)  
* gnumake (or any other flavor)  

Also at `.nix/derivation.nix` the nix build env is specified.  
If any other questions arise you can check the supplied dependencies and install process there.  

### Install into your env  

`PREFIX` env variable decides where the install directory lives. Default is `/usr/local`

* `make install`  

## If keltest is available in env  

This really is the recommended case. Put things in your env. That's why it exists. Drop in your build container if you must, but just put it in your env.  

Currently just compile each test file with a compiler of your choice with  

`c++ -std=c++17 test_file_a.cpp -c -o test_file_a.o`  
`c++ -std=c++17 test_file_b.cpp -c -o test_file_b.o`  

and generate a test binary with  

`c++ -std=c++17 -lkeltest test_file_a.o test_file_b.o -o tests`  

See `./example` for an example setup.  

## Modified commands if not available in env  

`c++ -std=c++17 test_file_a.cpp -I${keltest_src} -c -o test_file_a.o`  
`c++ -std=c++17 test_file_b.cpp -I${keltest_src} -c -o test_file_b.o`  
`c++ -std=c++17 -DKELTEST_COMPILE_TEST_BINARY ${keltest_src}/keltest/test.cpp test_file_a.o test_file_b.o -o tests`  

# Writing tests  

It is necessary to wrap the tests in an anonymous namespace due to how the test case names are generated. An example test file would be  

```
// test_file_hello.cpp
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
```
