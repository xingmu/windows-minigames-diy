# Makefile for 082-Billiards (9-Ball Pool)
# Zen-C + 003-framework

PROJECT = 082-billiards
GAME_NAME = 9ball
SOURCE_DIR = src
BUILD_DIR = build
ZCC = zc

# 源文件
SOURCES = $(wildcard $(SOURCE_DIR)/*.zc)
# 从003-framework复制的基础文件
FRAMEWORK_SRC = ../003-framework/src

# 默认目标
all: windows

# Windows 构建 (需要 Zen-C 编译器)
windows:
	@echo "Building 9-Ball Pool for Windows..."
	@mkdir -p $(BUILD_DIR)
	@$(ZCC) -o $(BUILD_DIR)/$(GAME_NAME).exe $(SOURCES) 2>/dev/null || \
		echo "Note: Zen-C compiler not found. This is a template project."

# Linux/macOS 构建
unix:
	@echo "Building 9-Ball Pool for Unix..."
	@mkdir -p $(BUILD_DIR)
	@$(ZCC) -o $(BUILD_DIR)/$(GAME_NAME) $(SOURCES) 2>/dev/null || \
		echo "Note: Zen-C compiler not found. This is a template project."

# 清理
clean:
	@rm -rf $(BUILD_DIR)
	@echo "Cleaned build directory."

# 运行 (需要编译器)
run: windows
	@./$(BUILD_DIR)/$(GAME_NAME).exe

# 调试构建
debug:
	@mkdir -p $(BUILD_DIR)
	@$(ZCC) -g -o $(BUILD_DIR)/$(GAME_NAME)_debug $(SOURCES)

# 打包
package:
	@echo "Packaging $(PROJECT)..."
	@mkdir -p $(BUILD_DIR)/package
	@cp $(BUILD_DIR)/$(GAME_NAME).exe $(BUILD_DIR)/package/ 2>/dev/null || true
	@cp README.md $(BUILD_DIR)/package/
	@cp -r docs $(BUILD_DIR)/package/
	@echo "Package created in $(BUILD_DIR)/package/"

.PHONY: all windows unix clean run debug package
