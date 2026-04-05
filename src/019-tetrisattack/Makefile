# Makefile for TetrisAttack Game
# Zen-C 游戏项目

PROJECT_NAME = tetrisattack
FRAMEWORK_PATH = ../003-framework

# Zen-C 编译器
ZC = zcc
ZC_FLAGS = -std=c11 -O2

# 源文件
SRC_DIR = src
SRC_FILES = $(SRC_DIR)/main_window.zc $(SRC_DIR)/game_logic.zc $(SRC_DIR)/platform_api.zc $(SRC_DIR)/platform_api_windows.zc

# 输出
BUILD_DIR = build
TARGET = $(BUILD_DIR)/$(PROJECT_NAME)

# Windows 特定
WIN_TARGET = $(BUILD_DIR)/$(PROJECT_NAME).exe

.PHONY: all clean run help

all: $(BUILD_DIR) $(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Linux/macOS 构建
$(TARGET): $(SRC_FILES)
	@echo "Building $(PROJECT_NAME)..."
	$(ZC) $(ZC_FLAGS) -o $(TARGET) $(SRC_FILES)
	@echo "Build complete: $(TARGET)"

# Windows 构建 (使用 zcc.exe)
$(WIN_TARGET): $(SRC_FILES)
	@echo "Building $(PROJECT_NAME) for Windows..."
	$(ZC) $(ZC_FLAGS) -o $(WIN_TARGET) $(SRC_FILES)
	@echo "Build complete: $(WIN_TARGET)"

# 运行游戏
run: $(TARGET)
	@echo "Starting $(PROJECT_NAME)..."
	$(TARGET)

# 清理
clean:
	rm -rf $(BUILD_DIR)
	@echo "Clean complete"

# 帮助
help:
	@echo "TetrisAttack Game Makefile"
	@echo ""
	@echo "Targets:"
	@echo "  all      - Build the game (default)"
	@echo "  run      - Build and run the game"
	@echo "  clean    - Remove build artifacts"
	@echo "  help     - Show this help message"
	@echo ""
	@echo "Usage:"
	@echo "  Linux/macOS: make && ./build/tetrisattack"
	@echo "  Windows:      make && ./build/tetrisattack.exe"
