.PHONY: all clean

PREFIX ?= /usr/local

all: build/libkeltest.a

build/libkeltest.a:
	mkdir -p ./build
	c++ -std=c++17 -DKELTEST_COMPILE_TEST_BINARY src/keltest/test.cpp -o build/test.o
	ar q build/libkeltest.a build/test.o

clean:
	rm -rf ./build

install: build/libkeltest.a
	mkdir -p ${PREFIX}/lib
	mkdir -p ${PREFIX}/include/keltest
	cp build/libkeltest.a ${PREFIX}/lib/libkeltest.a
	cp src/keltest/test.h ${PREFIX}/include/keltest/test.h
