# Project Settings
SRC_DIR := ./src

# Compiler Settings
CFLAGS := -std=c2x -Wall -Wextra -pedantic
LFLAGS := -lm

# Executables
binary-search: ./bin/binary-search

# Binaries
./bin/binary-search: ./build/binary-search.o | ./bin
	cc $(CFLAGS) -o $@ $^ $(LFLAGS)

# Object Files
./build/binary-search.o: ./src/binary-search.c | ./build
	cc $(CFLAGS) -c $^ -o $@

# Directories
./build:
	mkdir -p $@

./bin:
	mkdir -p $@

clean:
	rm -rf ./build ./bin

.PHONY: clean