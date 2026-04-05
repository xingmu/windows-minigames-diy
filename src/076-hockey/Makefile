# Zen-C Hockey Game Makefile
# 使用zc编译器构建Zen-C项目

ZC = zc
CC = gcc
TARGET = hockey_game

SRC = src/main_window.zc
OUT = build/$(TARGET)

all: $(OUT)

$(OUT): $(SRC)
	@mkdir -p build
	$(ZC) build -o $(OUT) $(SRC)

run: $(OUT)
	./$(OUT)

clean:
	rm -rf build/

test:
	@echo "Testing Zen-C..."
	@which $(ZC) || echo "zc not found"

help:
	@echo "Zen-C Hockey Game"
	@echo "  make all   - build"
	@echo "  make run   - run game"
	@echo "  make clean - cleanup"

.PHONY: all run clean test help
