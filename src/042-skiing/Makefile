# Zen-C Skiing Game Makefile
ZC = zc
TARGET = skiing
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

test:
	@echo "测试Zen-C编译..."
	@if command -v $(ZC) >/dev/null 2>&1; then echo "✅ zc编译器已安装"; $(ZC) --version; else echo "❌ zc编译器未安装"; exit 1; fi

help:
	@echo "Zen-C Skiing Game 构建系统"
	@echo "  make all     - 编译游戏"
	@echo "  make run     - 运行游戏"
	@echo "  make windows - Windows构建"

.PHONY: all run windows test help
