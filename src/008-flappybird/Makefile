# FlappyBird Zen-C Game Makefile
# 使用 zc 编译器构建 Zen-C 项目

# 编译器设置
ZC = zc
CC = gcc
CFLAGS = -Wall -Wextra -O2
TARGET = flappybird
OUT_DIR = build

# 源文件
SRC = src/main_window.zc
OUT = $(OUT_DIR)/$(TARGET)

# 默认目标
all: $(OUT)

# 编译 Zen-C 代码
$(OUT): $(SRC)
	@mkdir -p $(OUT_DIR)
	$(ZC) build -o $(OUT) $(SRC)

# 运行游戏
run: $(OUT)
	./$(OUT)

# 清理构建文件
clean:
	rm -rf $(OUT_DIR)/

# 安装依赖
install-deps:
	@echo "请从 https://github.com/z-libs/Zen-C 安装 zc 编译器"
	@echo ""
	@echo "安装方法:"
	@echo "  git clone https://github.com/z-libs/Zen-C.git"
	@echo "  cd Zen-C"
	@echo "  mkdir build && cd build"
	@echo "  cmake .. -DCMAKE_BUILD_TYPE=Release"
	@echo "  cmake --build . --config Release"
	@echo "  # 将 build/zc 添加到系统 PATH"

# 测试编译
test:
	@echo "测试 Zen-C 编译..."
	@if command -v $(ZC) >/dev/null 2>&1; then \
		echo "✅ zc 编译器已安装"; \
		$(ZC) --version; \
	else \
		echo "❌ 错误: zc 编译器未安装"; \
		echo "请运行: make install-deps 查看安装说明"; \
		exit 1; \
	fi

# 显示帮助
help:
	@echo "FlappyBird Zen-C Game 构建系统"
	@echo ""
	@echo "可用命令:"
	@echo "  make all      - 编译游戏 (默认)"
	@echo "  make run      - 编译并运行游戏"
	@echo "  make clean    - 清理构建文件"
	@echo "  make test     - 测试编译器安装"
	@echo "  make help     - 显示此帮助信息"
	@echo ""
	@echo "源文件结构:"
	@echo "  src/main_window.zc           - 游戏主程序"
	@echo "  src/platform_api.zc         - 平台 API 接口"
	@echo "  src/platform_api_windows.zc - Windows 平台实现"
	@echo ""
	@echo "依赖:"
	@echo "  - zc 编译器 (Zen-C 编译器)"
	@echo "  - gcc 编译器 (C 后端，用于 MinGW)"
	@echo ""
	@echo "安装 zc 编译器:"
	@echo "  git clone https://github.com/z-libs/Zen-C.git"
	@echo "  cd Zen-C && mkdir build && cd build"
	@echo "  cmake .. -DCMAKE_BUILD_TYPE=Release"
	@echo "  cmake --build . --config Release"

.PHONY: all run clean test help install-deps
