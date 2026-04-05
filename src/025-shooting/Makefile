# Zen-C Shooting Gallery Game Makefile

ZC = zc
CC = gcc
CFLAGS = -Wall -Wextra -O2
TARGET = shooting

SRC = src/main_window.zc
OUT = build/$(TARGET)

all: $(OUT)

$(OUT): $(SRC)
	@mkdir -p build
	$(ZC) build -o $(OUT) $(SRC)

run: $(OUT)
	./$(OUT)

windows:
	@mkdir -p build
	$(ZC) build -o build/$(TARGET).exe $(SRC)

clean:
	cd build && rm -f $(TARGET) $(TARGET).exe

test:
	@echo "测试Zen-C编译..."
	@if command -v $(ZC) >/dev/null 2>&1; then \
		echo "zc编译器已安装"; \
		$(ZC) --version; \
	else \
		echo "错误: zc编译器未安装"; \
		exit 1; \
	fi

help:
	@echo "Zen-C Shooting Gallery 构建系统"
	@echo ""
	@echo "可用命令:"
	@echo "  make all      - 编译游戏 (默认)"
	@echo "  make run      - 编译并运行游戏"
	@echo "  make windows  - 编译Windows可执行文件"
	@echo "  make clean    - 清理构建文件"
	@echo "  make test     - 测试编译器安装"
	@echo "  make help     - 显示此帮助信息"

.PHONY: all run windows clean test help
