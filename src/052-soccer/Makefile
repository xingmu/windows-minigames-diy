# Makefile for 052-Soccer - Zen-C足球点球游戏

# 编译器设置
CC = gcc
CFLAGS = -Wall -Wextra -I.

# Zen-C 编译器
ZC = zc
ZCFLAGS = 

# 源文件
SRC_DIR = src
SRC_FILES = $(SRC_DIR)/main_window.zc $(SRC_DIR)/game_logic.zc $(SRC_DIR)/platform_api.zc

# 目标文件
TARGET = soccer
OBJ_DIR = obj

# 平台检测
ifeq ($(OS),Windows_NT)
    PLATFORM = windows
    EXE = .exe
else
    PLATFORM = unix
    EXE =
endif

.PHONY: all clean run

all: $(TARGET)$(EXE)

$(TARGET)$(EXE): $(SRC_FILES)
	@echo "Building 052-Soccer..."
	$(ZC) $(ZCFLAGS) -o $@ $(SRC_FILES)

clean:
	@echo "Cleaning..."
	rm -f $(TARGET)$(EXE)
	rm -rf $(OBJ_DIR)

run: $(TARGET)$(EXE)
	@echo "Running 052-Soccer..."
	./$(TARGET)$(EXE)

windows:
	./build_windows.bat

help:
	@echo "052-Soccer - Zen-C足球点球游戏"
	@echo ""
	@echo "Targets:"
	@echo "  all      - 编译游戏 (默认)"
	@echo "  clean    - 清理生成的文件"
	@echo "  run      - 编译并运行游戏"
	@echo "  windows  - Windows平台编译脚本"
	@echo "  help     - 显示帮助信息"
