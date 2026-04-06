# Makefile for Rugby - Zen-C Game

ZENC = zenc
CFLAGS = -O2

SRC_DIR = src
BUILD_DIR = build

SOURCES = $(SRC_DIR)/main_window.zc $(SRC_DIR)/game.zc \
          $(SRC_DIR)/game_logic.zc $(SRC_DIR)/platform_api.zc \
          $(SRC_DIR)/platform_api_windows.zc

TARGET = $(BUILD_DIR)/rugby

.PHONY: all clean run

all: $(BUILD_DIR)
	@echo "Building Rugby..."
	$(ZENC) $(SOURCES) -o $(TARGET) $(CFLAGS)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

run: all
	./$(TARGET)

clean:
	cd $(BUILD_DIR) && del /q *.* 2>nul
	@echo "Clean complete"