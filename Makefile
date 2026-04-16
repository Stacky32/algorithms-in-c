CC=gcc
AR=ar
CFLAGS=-Wall -Wextra -Wvla -std=c2x -Iinclude -MMD -MP

SRC:=$(shell find src -name '*.c' | sort)
TEST:=$(shell find tests -name '*.c' | sort)

OBJ=$(SRC:src/%.c=build/%.o)
TOBJ=$(TEST:tests/%.c=build/tests/%.o)

.PHONY: all clean test
all: libalgos.a run_tests

clean:
	rm -rf build *.a run_tests

test: run_tests
	./run_tests

libalgos.a: $(OBJ)
	ar rcs $@ $^

run_tests: $(TOBJ) libalgos.a
	$(CC) $(CFLAGS) -o $@ $(TOBJ) -L. -lalgos

build/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

build/tests/%.o: tests/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

-include $(OBJ:.o=.d) $(TOBJ:.o=.d)

# --- Formatting ---
FORMAT_SRC := $(shell find src include tests -name "*.c" -o -name "*.h")

.PHONY: format format-check

format:
	@echo "Formatting source files..."
	@clang-format -i $(FORMAT_SRC)

format_check:
	@echo "Checking formatting..."
	@clang-format --dry-run --Werror $(FORMAT_SRC)