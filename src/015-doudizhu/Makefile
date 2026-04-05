# Zen-C 斗地主游戏 Makefile
ZC = zc
CC = gcc
TARGET = doudizhu_game
SRC = src/main_window.zc
OUT = build/$(TARGET)

all: $(OUT)

$(OUT): $(SRC)
	@mkdir -p build
	$(ZC) build -o $(OUT) $(SRC)

run: $(OUT)
	./$(OUT)

clean:
	find build -type f -delete 2>/dev/null; rmdir build 2>/dev/null; true

install-deps:
	@echo 请从 https://github.com/z-libs/Zen-C 安装zc编译器

test:
	@if command -v $(ZC) >/dev/null 2>&1; then echo zc已安装; $(ZC) --version; else echo zc未安装; fi

help:
	@echo Zen-C 斗地主游戏构建系统

.PHONY: all run clean test help install-deps
