# Zen-C Pingpong 2P Makefile
ZC = zc
TARGET = pingpong2p
SRC = src/main_window.zc
OUT = build/$(TARGET)

all: $(OUT)

$(OUT): $(SRC)
	@mkdir -p build
	$(ZC) build -o $(OUT) $(SRC)

run: $(OUT)
	./$(OUT)

help:
	@echo "Zen-C Pingpong 2P Build System"

.PHONY: all run help
