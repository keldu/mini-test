.PHONY: all clean

PREFIX ?= /usr/local

all: build/example

build/example:
	mkdir -p ./build
	c++ -std=c++17 -lkeltest example.cpp -o build/example

clean:
	rm -rf ./build

install: build/example
	mkdir -p ${PREFIX}/bin
	cp build/example ${PREFIX}/bin/example
