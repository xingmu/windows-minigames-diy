# Makefile for Zen-C Sokoban Game
# 使用 003-framework 框架

# 编译器
ZC = zc
CC = gcc

# 源文件目录
SRC_DIR = src
BUILD_DIR = build

# 源文件
ZC_SOURCES = $(SRC_DIR)/main_window.zc $(SRC_DIR)/sokoban_logic.zc
PLATFORM_SOURCES = $(SRC_DIR)/platform_api.zc $(SRC_DIR)/game.zc
ALL_ZC = $(ZC_SOURCES) $(PLATFORM_SOURCES)

# 目标文件
ZC_TARGET = $(BUILD_DIR)/sokoban_game.z.c

# 最终可执行文件
TARGET = $(BUILD_DIR)/sokoban_game.exe

# 编译选项
ZC_FLAGS = -target x86_64-pc-windows-gnu
CC_FLAGS = -Wall -Wextra -O2

# 头文件目录
INCLUDE_DIRS = -I$(SRC_DIR)

.PHONY: all clean run

all: $(TARGET)

# Zen-C 编译
$(ZC_TARGET): $(ALL_ZC)
	@mkdir -p $(BUILD_DIR)
	$(ZC) compile $(ZC_FLAGS) -o $(ZC_TARGET) $(ALL_ZC)

# C 编译
$(TARGET): $(ZC_TARGET)
	$(CC) $(CC_FLAGS) $(ZC_TARGET) -o $(TARGET) -lwin32 -lgdi32 -luser32 -lkernel32

# 运行游戏
run: $(TARGET)
	./$(TARGET)

# 清理
clean:
	rm -rf $(BUILD_DIR)

# 默认目标
all: $(TARGET)
