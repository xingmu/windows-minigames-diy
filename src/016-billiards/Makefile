# Zen-C 台球游戏 Makefile
ZC = zc
TARGET = billiards
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
	-rm -f build/$(TARGET) build/$(TARGET).exe

test:
	@echo "Testing Zen-C compiler..."
	@if command -v $(ZC) >/dev/null 2>&1; then \
		echo "OK: zc compiler found"; \
	else \
		echo "ERROR: zc compiler not found"; \
		exit 1; \
	fi

help:
	@echo "Zen-C 台球游戏 构建系统"
	@echo "可用命令:"
	@echo "  make all     - 编译游戏 (默认)"
	@echo "  make run     - 编译并运行游戏"
	@echo "  make windows - 编译Windows可执行文件"
	@echo "  make clean   - 清理构建文件"
	@echo "  make test    - 测试编译器安装"
	@echo "  make help    - 显示帮助"

.PHONY: all run windows clean test help
