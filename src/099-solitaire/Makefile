# Zen-C Solitaire Game Makefile
ZC = zc
CC = gcc
TARGET = solitaire
SRC = src/main_window.zc
OUT = build/$(TARGET)

all: $(OUT)

$(OUT): $(SRC)
	@mkdir -p build
	$(ZC) build -o $(OUT) $(SRC)

run: $(OUT)
	./$(OUT)

clean:
	-find build -type f -delete 2>/dev/null; rmdir build 2>/dev/null; true

install-deps:
	@echo "Install zc from https://github.com/z-libs/Zen-C"

test:
	@if command -v $(ZC) >/dev/null 2>&1; then echo "zc found"; else echo "zc not found"; fi

help:
	@echo "Solitaire build system"

.PHONY: all run clean test help install-deps
