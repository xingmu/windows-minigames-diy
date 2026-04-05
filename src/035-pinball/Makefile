# Makefile - Zen-C Pinball 弹球机游戏构建配置

.PHONY: all build clean run

SRC_DIR = src
BUILD_DIR = build
OUT_NAME = pinball

all: build

build:
	@echo "编译 Pinball..."
	@mkdir -p $(BUILD_DIR)
	zc build $(SRC_DIR)/main_window.zc -o $(BUILD_DIR)/$(OUT_NAME) -I$(SRC_DIR)

run: build
	@echo "运行 Pinball..."
	./$(BUILD_DIR)/$(OUT_NAME)

clean:
	@echo "清理构建文件..."
	@rm -rf $(BUILD_DIR)

windows:
	@echo "Windows 构建..."
	./build_windows.bat
