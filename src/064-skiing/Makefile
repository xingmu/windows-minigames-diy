# Zen-C Skiing Game Makefile

ZC = zc
CC = gcc
TARGET = skiing
SRC = src/main_window.zc
OUT = build/$(TARGET)

all: $(OUT)

$(OUT): $(SRC)
	@mkdir -p build
	$(ZC) build -o $(OUT) $(SRC)

run: $(OUT)
	./$(OUT)

windows:
	@mkdir -p build
	$(ZC) build -o build/$(TARGET).exe $(SRC)

clean:
	rm -f build/$(TARGET) build/$(TARGET).exe

test:
	@$(ZC) --version 2>/dev/null || echo "zc not found"

help:
	@echo "Skiing Game - 可用命令: all, run, windows, clean, test, help"

.PHONY: all run windows clean test help
