# Zen-C TetrisPlus Makefile

ZC = zc
GCC = gcc

SRC_DIR = src
SRC = $(SRC_DIR)/main_window.zc

TARGET = build/tetrisplus_game.exe

ZC_FLAGS = build -o $(TARGET)
CFLAGS = -Wall -O2

.PHONY: all clean build windows

all: build

build: 
	mkdir -p build
	$(ZC) $(ZC_FLAGS) $(SRC)

windows: build

clean:
	rm -f build/*.exe
	rm -f build/*.o
	rm -f build/*.c
	rm -f build/*.h
