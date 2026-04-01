SRC_DIR = src
TEST_DIR = tests
BUILD_DIR = build
BIN_DIR = bin

CFLAGS = -Wall -Wextra -std=c2x -Iinclude -MMD -MP

SRC_FILES = $(shell find $(SRC_DIR) -name '*.c')
TEST_FILES = $(shell find $(TEST_DIR) -name '*.c')

SRC_OBJS = $(SRC_FILES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
TEST_OBJS = $(TEST_FILES:$(TEST_DIR)/%.c=$(BUILD_DIR)/tests/%.o)

TARGET = algolib
TEST_TARGET = run_tests

# Build library (object files only)
$(TARGET): $(SRC_OBJS)
	@echo "Library compiled."

# Build test runner
$(TEST_TARGET): $(SRC_OBJS) $(TEST_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compile source files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Compile test files
$(BUILD_DIR)/tests/%.o: $(TEST_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Include dependencies
-include $(OBJS:.o=.d)

clean:
	rm -rf $(BUILD_DIR) $(TEST_TARGET)