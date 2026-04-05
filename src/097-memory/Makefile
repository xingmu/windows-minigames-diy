# Makefile for 097-Memory Game
PROJECT_NAME = memory

ZC = zcc
ZC_FLAGS = -std=c11 -O2

SRC_DIR = src
SRC_FILES = $(SRC_DIR)/main_window.zc $(SRC_DIR)/game_logic.zc $(SRC_DIR)/platform_api.zc

BUILD_DIR = build
TARGET = $(BUILD_DIR)/$(PROJECT_NAME)
WIN_TARGET = $(BUILD_DIR)/$(PROJECT_NAME).exe

.PHONY: all clean run help

all: $(BUILD_DIR) $(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(TARGET): $(SRC_FILES)
	@echo "Building $(PROJECT_NAME)..."
	$(ZC) $(ZC_FLAGS) -o $(TARGET) $(SRC_FILES)
	@echo "Build complete: $(TARGET)"

$(WIN_TARGET): $(SRC_FILES)
	@echo "Building $(PROJECT_NAME) for Windows..."
	$(ZC) $(ZC_FLAGS) -o $(WIN_TARGET) $(SRC_FILES)
	@echo "Build complete: $(WIN_TARGET)"

run: $(TARGET)
	@echo "Starting $(PROJECT_NAME)..."
	$(TARGET)

clean:
	rm -r $(BUILD_DIR)
	@echo "Clean complete"

help:
	@echo "097-Memory Game Makefile"
	@echo "Usage:"
	@echo "  make        - Build the game"
	@echo "  make run    - Build and run"
	@echo "  make clean  - Clean build files"
