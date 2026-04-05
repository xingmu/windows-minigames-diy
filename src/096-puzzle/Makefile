# Zen-C 096-Puzzle Makefile
# 使用zc编译器构建Zen-C项目

ZC = zc
CC = gcc
TARGET = puzzle_game
SRC = src/main_window.zc
OUT = build/$(TARGET)

all: $(OUT)

$(OUT): $(SRC)
	@mkdir -p build
	$(ZC) build -o $(OUT) $(SRC)

run: $(OUT)
	./$(OUT)

clean:
	cd build && rm -f $(TARGET) 2>/dev/null; cd ..

test:
	@which $(ZC) && $(ZC) --version || echo "zc not found"

help:
	@echo "Zen-C 096-Puzzle - make all/run/clean/test"

.PHONY: all run clean test help
