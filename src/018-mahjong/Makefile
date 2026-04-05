# Zen-C Mahjong Makefile

# 编译器
ZC = zc
GCC = gcc

# 源文件
SRC_DIR = src
SRC = $(SRC_DIR)/main_window.zc

# 目标文件
TARGET = build/mahjong_game.exe

# 编译选项
ZC_FLAGS = build -o $(TARGET)
CFLAGS = -Wall -O2

.PHONY: all clean build windows

all: build

build: 
	$(ZC) $(ZC_FLAGS) $(SRC)

windows: build

clean:
	cd build && del /Q *.exe *.o *.c *.h 2>nul
