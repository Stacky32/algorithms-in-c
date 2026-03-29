# Compiler Settings
CFLAGS := -std=c2x -Wall -Wextra -pedantic
LFLAGS := -lm

TARGETS := binary-search selection-sort

BIN := $(TARGETS:%=./bin/%)
OBJ := $(TARGETS:%=./build/%.o)

all: $(BIN)

./bin/%: ./build/%.o | ./bin
	cc $(CFLAGS) -o $@ $^ $(LFLAGS)

./build/%.o: ./src/%.c | ./build
	cc $(CFLAGS) -c $< -o $@

# Directories
./build:
	mkdir -p $@

./bin:
	mkdir -p $@

clean:
	rm -rf ./build ./bin

.PHONY: clean