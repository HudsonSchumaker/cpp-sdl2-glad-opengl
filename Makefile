# Compiler and flags
CXX = g++
CC = gcc
CXXFLAGS = -Wall -Wextra -std=c++17 -O3 -Iinclude -I/usr/include/SDL2 -D_REENTRANT
CFLAGS = -Wall -Wextra -std=c17 -O3 -Iinclude
LDFLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

# Directories
SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = include

# Find all source files
SRCS = $(shell find $(SRC_DIR) -name '*.cpp' -or -name '*.c')
OBJS = $(patsubst $(SRC_DIR)/%,$(BUILD_DIR)/%,$(SRCS:.cpp=.o))
OBJS := $(patsubst $(SRC_DIR)/%,$(BUILD_DIR)/%,$(OBJS:.c=.o))

# Target executable
TARGET = $(BUILD_DIR)/demo

# Default target
all: $(TARGET)

# Build target
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

# Build object files from .cpp files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Build object files from .c files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Create build directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean build files
clean:
	rm -rf $(BUILD_DIR)

# Precompiled header
$(BUILD_DIR)/pch.h.gch: $(INCLUDE_DIR)/Pch.hpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -x c++-header $(INCLUDE_DIR)/Pch.hpp -o $@

# Include precompiled header in source files
$(SRC_DIR)/%.cpp: $(BUILD_DIR)/pch.h.gch

.PHONY: all clean