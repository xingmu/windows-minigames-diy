CC = gcc
ZC = zc
TARGET = shuffleboard
SRC_DIR = src
BUILD_DIR = build

SOURCES = $(SRC_DIR)/main_window.zc
EXECUTABLE = $(BUILD_DIR)/$(TARGET)

.PHONY: all clean build run

all: build

build:
	@echo "Building Zen-C Shuffleboard..."
	@mkdir -p $(BUILD_DIR)
	$(ZC) build $(SOURCES) -o $(EXECUTABLE)
	@echo "Build complete: $(EXECUTABLE)"

run: build
	@echo "Running..."
	./$(EXECUTABLE)

clean:
	@echo "Cleaning..."
	@rm -rf $(BUILD_DIR)
