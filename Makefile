# Directories
SRC_DIR := src
TEST_DIR := tests
BUILD_DIR := build

# Compiler
CFLAGS := -Wall -Wextra -Wvla -std=c2x -Iinclude -MMD -MP

# File discovery
SRC_FILES := $(shell find $(SRC_DIR) -name '*.c' | sort)
TEST_FILES := $(shell find $(TEST_DIR) -name '*.c' | sort)

# Object files
SRC_OBJS := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC_FILES))
TEST_OBJS := $(patsubst $(TEST_DIR)/%.c,$(BUILD_DIR)/tests/%.o,$(TEST_FILES))

OBJS := $(SRC_OBJS) $(TEST_OBJS)

# Targets
TEST_TARGET := run_tests

.PHONY: all clean
all: $(TEST_TARGET)

clean:
	rm -rf $(BUILD_DIR) $(TEST_TARGET)

# Link test binary
$(TEST_TARGET): $(SRC_OBJS) $(TEST_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# --- Compilation rules ---
# Source files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Test files
$(BUILD_DIR)/tests/%.o: $(TEST_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Dependencies
-include $(OBJS:.o=.d)
