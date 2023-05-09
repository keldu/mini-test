.PHONY: all clean

all: build/libkeltest.a

build/libkeltest.a:
	mkdir -p ./build
	c++ -std=c++17 -DKELTEST_COMPILE_TEST_BINARY src/keltest/test.cpp -o build/test.o
	ar build/libkeltest.a build/test.o

clean:
	rm -rf ./build

install: build/libkeltest.a
	mkdir -p ${prefix}/lib
	mkdir -p ${prefix}/include/keltest
	cp build/libkeltest.a ${prefix}/lib/libkeltest.a
	cp src/keltest/test.h ${prefix}/include/keltest/test.h
