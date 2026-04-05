# 2048 Game Makefile
# 使用zc编译器构建Zen-C项目

# 编译器设置
ZC = zc
CC = gcc
CFLAGS = -Wall -Wextra -O2
TARGET = game2048

# 源文件 - 入口文件是 main_window.zc
SRC = src/main_window.zc
OUT = build/$(TARGET)

# 框架路径
FRAMEWORK_PATH = ../003-framework/src

# 默认目标
all: dirs $(OUT)

# 编译Zen-C代码
$(OUT): $(SRC)
	@echo "Compiling 2048 game..."
	$(ZC) build -o $(OUT) $(SRC)
	@echo "Build complete: $(OUT)"

# 创建build目录
dirs:
	@mkdir -p build

# 运行游戏
run: $(OUT)
	./$(OUT)

# 清理构建文件
clean:
	rm -r build

# Windows交叉编译（在Linux上使用mingw）
windows: clean dirs
	@echo "Cross-compiling for Windows..."
	$(ZC) build --target=windows -o $(OUT).exe $(SRC)

# 测试编译
test:
	@echo "Testing Zen-C compiler..."
	@if command -v $(ZC) >/dev/null 2>&1; then \
		echo "zc compiler found"; \
	else \
		echo "Error: zc compiler not found"; \
		exit 1; \
	fi

# 安装依赖
install-deps:
	@echo "Installing Zen-C compiler..."
	@echo "Please follow instructions at: https://github.com/z-libs/Zen-C"

# 显示帮助
help:
	@echo "2048 Game Build System"
	@echo ""
	@echo "Available targets:"
	@echo "  make all      - Compile game (default)"
	@echo "  make run      - Compile and run game"
	@echo "  make clean    - Clean build files"
	@echo "  make windows  - Cross-compile for Windows"
	@echo "  make test     - Test compiler installation"
	@echo "  make help     - Show this help"

.PHONY: all run clean windows test help install-deps dirs
