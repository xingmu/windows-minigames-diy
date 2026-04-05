# Zen-C Boat Racing Game Makefile
# 063-Boat 赛艇大赛

ZC = zc
TARGET = boat_game
SRC = src/main_window.zc
OUT = build/$(TARGET)

all: $(OUT)

$(OUT): $(SRC)
	@mkdir -p build
	$(ZC) build -o $(OUT) $(SRC)

run: $(OUT)
	./$(OUT)

test:
	@echo test

help:
	@echo Boat Racing build
