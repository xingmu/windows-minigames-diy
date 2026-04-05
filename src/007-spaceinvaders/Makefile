# Space Invaders Makefile
# 使用zc编译器构建Zen-C项目

# 编译器设置
ZC = zc
CC = gcc
CFLAGS = -Wall -Wextra -O2
TARGET = spaceinvaders

# 源文件
SRC = src/main_window.zc
OUT = build/$(TARGET)

# 默认目标
all: $(OUT)

# 编译Zen-C代码
$(OUT): $(SRC)
	@mkdir -p build
	$(ZC) build -o $(OUT) $(SRC)

# 运行游戏
run: $(OUT)
	./$(OUT)

# 清理构建文件
clean:
	rm -rf build/

# 安装依赖
install-deps:
	@echo "请从 https://github.com/z-libs/Zen-C 安装zc编译器"

# 测试编译
test:
	@echo "测试Zen-C编译..."
	@if command -v $(ZC) >/dev/null 2>&1; then \
		echo "zc编译器已安装"; \
		$(ZC) --version; \
	else \
		echo "错误: zc编译器未安装"; \
		exit 1; \
	fi

.PHONY: all run clean test install-deps
