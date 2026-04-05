# Zen-C Tetris Makefile

# 编译器
ZC = zc
GCC = gcc

# 源文件
SRC_DIR = src
SRC = $(SRC_DIR)/main_window.zc

# 目标文件
TARGET = build/tetris_game.exe

# 编译选项
ZC_FLAGS = build -o $(TARGET)
CFLAGS = -Wall -O2

.PHONY: all clean build windows

all: build

build: 
	$(ZC) $(ZC_FLAGS) $(SRC)

windows: build

clean:
	rm -rf build/*.exe
	rm -rf build/*.o
	rm -rf build/*.c
	rm -rf build/*.h
