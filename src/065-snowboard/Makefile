# Snowboard Zen-C Game Makefile
ZC = zc
CC = gcc
TARGET = snowboard
OUT_DIR = build
SRC = src/main_window.zc
OUT = $(OUT_DIR)/$(TARGET)

all: $(OUT)

$(OUT): $(SRC)
	@mkdir -p $(OUT_DIR)
	$(ZC) build -o $(OUT) $(SRC)

run: $(OUT)
	./$(OUT)

clean:
	rm -f $(OUT_DIR)/$(TARGET)

test:
	@if command -v $(ZC) >/dev/null 2>&1; then echo "zc 已安装"; else echo "zc 未安装"; fi

help:
	@echo "Snowboard Zen-C - 可用命令: all, run, clean, test, help"

.PHONY: all run clean test help
