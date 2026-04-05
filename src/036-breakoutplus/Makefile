# Makefile for BreakoutPlus
# Zen-C 打砖块增强版构建配置

COMPILER = zc
SRC_DIR = src
BUILD_DIR = build
TARGET = breakoutplus

SOURCES = $(SRC_DIR)/main_window.zc $(SRC_DIR)/platform_api.zc $(SRC_DIR)/game_logic.zc
OBJECTS = $(BUILD_DIR)/$(TARGET)

CFLAGS = -O2
LDFLAGS =

.PHONY: all clean run

all: $(BUILD_DIR)/$(TARGET)

$(BUILD_DIR)/$(TARGET): $(SOURCES)
	@mkdir -p $(BUILD_DIR)
	$(COMPILER) $(SRC_DIR)/main_window.zc -o $(OBJECTS) $(CFLAGS) $(LDFLAGS)

clean:
	rm -f $(BUILD_DIR)/*

run: $(BUILD_DIR)/$(TARGET)
	./$(BUILD_DIR)/$(TARGET)
