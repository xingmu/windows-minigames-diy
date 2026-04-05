# Zen-C Boxing Game Makefile
# 使用zc编译器构建Zen-C项目

ZC = zc
CC = gcc
CFLAGS = -Wall -Wextra -O2
TARGET = boxing
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

test:
	@echo "Testing Zen-C compiler..."
	@if command -v $(ZC) >/dev/null 2>&1; then \
		echo "zc compiler found"; \
		$(ZC) --version; \
	else \
		echo "zc compiler not found"; \
		exit 1; \
	fi

help:
	@echo "Zen-C Boxing Game"
	@echo "  make all     - build game"
	@echo "  make run     - build and run"
	@echo "  make windows - build for Windows"
	@echo "Controls: W/A/S/D move, J/Space jab, K/Enter hook"

.PHONY: all run windows test help
