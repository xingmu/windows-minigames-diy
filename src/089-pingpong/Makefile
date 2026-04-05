# 089-Pingpong Makefile
# Zen-C 乒乓球街机版

# 编译器
ZC = zc
GCC = gcc

# 源文件
SRC_DIR = src
BUILD_DIR = build
FRAMEWORK_DIR = ../003-framework/src

SRC_FILES = $(SRC_DIR)/main_window.zc $(SRC_DIR)/game.zc $(SRC_DIR)/game_logic.zc $(SRC_DIR)/platform_api.zc $(SRC_DIR)/platform_api_windows.zc

# 目标文件
OBJS = $(BUILD_DIR)/main_window.c $(BUILD_DIR)/game.c $(BUILD_DIR)/game_logic.c $(BUILD_DIR)/platform_api.c $(BUILD_DIR)/platform_api_windows.c

# 最终目标
TARGET = $(BUILD_DIR)/pingpong_game

# 清理
.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BUILD_DIR)
	$(GCC) -o $@ $(OBJS) -lwinmm -lgdi32 -luser32 -lm
	@echo "构建完成: $@"

$(BUILD_DIR)/main_window.c: $(SRC_DIR)/main_window.zc $(SRC_DIR)/platform_api.zc $(SRC_DIR)/game.zc $(SRC_DIR)/game_logic.zc
	@mkdir -p $(BUILD_DIR)
	$(ZC) -target windows -o $@ $<

$(BUILD_DIR)/game.c: $(SRC_DIR)/game.zc $(SRC_DIR)/platform_api.zc
	@mkdir -p $(BUILD_DIR)
	$(ZC) -target windows -o $@ $<

$(BUILD_DIR)/game_logic.c: $(SRC_DIR)/game_logic.zc $(SRC_DIR)/game.zc $(SRC_DIR)/platform_api.zc
	@mkdir -p $(BUILD_DIR)
	$(ZC) -target windows -o $@ $<

$(BUILD_DIR)/platform_api.c: $(SRC_DIR)/platform_api.zc
	@mkdir -p $(BUILD_DIR)
	$(ZC) -target windows -o $@ $<

$(BUILD_DIR)/platform_api_windows.c: $(SRC_DIR)/platform_api_windows.zc $(SRC_DIR)/platform_api.zc
	@mkdir -p $(BUILD_DIR)
	$(ZC) -target windows -o $@ $<

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(BUILD_DIR)/*.o $(BUILD_DIR)/*.c $(TARGET)
