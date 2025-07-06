# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -Iinclude

# Directories
SRC_DIR = src
BUILD_DIR = build
DIST_DIR = dist

# Source and object files
SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SOURCES))

# Final executable
TARGET = calendar

# Default build target
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS)

# Rule for compiling .c files into .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build and output
clean:
	rm -rf $(BUILD_DIR) $(TARGET) $(DIST_DIR)

# Install to dist folder (optional)
install: $(TARGET)
	@mkdir -p $(DIST_DIR)
	cp $(TARGET) $(DIST_DIR)/

# Run directly
run: install
	./$(DIST_DIR)/$(TARGET)

.PHONY: clean install run
