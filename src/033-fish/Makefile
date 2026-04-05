# Makefile for 033-FishGame
# 捕鱼达人风格游戏

.PHONY: all clean run

# Zen-C 编译器
ZC = zc

# 源文件目录
SRC_DIR = src
BUILD_DIR = build

# 源文件
SOURCES = $(SRC_DIR)/platform_api.zc \
          $(SRC_DIR)/platform_api_windows.zc \
          $(SRC_DIR)/game_logic.zc \
          $(SRC_DIR)/fish_render.zc \
          $(SRC_DIR)/main_window.zc

# 输出可执行文件
TARGET = $(BUILD_DIR)/fishgame

# 编译选项
ZC_FLAGS = -O2

all: $(BUILD_DIR) $(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(TARGET): $(SOURCES)
	$(ZC) $(ZC_FLAGS) -o $(TARGET) $(SOURCES)

clean:
	cd $(BUILD_DIR) && del /Q *.exe 2>nul || true

run: $(TARGET)
	./$(TARGET)
