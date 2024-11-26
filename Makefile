# Compiler and flags
CC = g++
CFLAGS = -Wall -Wextra -std=c17 -Iinclude -I/usr/include/SDL2 -D_REENTRANT
LDFLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

# Directories
SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = include

# Source and object files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

# Target executable
TARGET = $(BUILD_DIR)/demo

# Default target
all: $(TARGET)

# Build target
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

# Build object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create build directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean build files
clean:
	rm -rf $(BUILD_DIR)

# Precompiled header
$(BUILD_DIR)/pch.h.gch: $(INCLUDE_DIR)/Pch.hpp | $(BUILD_DIR)
	$(CC) $(CFLAGS) -x c-header $(INCLUDE_DIR)/Pch.hpp -o $@

# Include precompiled header in source files
$(SRC_DIR)/%.c: $(BUILD_DIR)/pch.h.gch

.PHONY: all clean