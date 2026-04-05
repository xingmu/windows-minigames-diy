# Zen-C Curling Game Makefile
# 使用zc编译器构建Zen-C项目

# 编译器设置
ZC = zc
TARGET = curling

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

# Windows构建
windows:
	@mkdir -p build
	$(ZC) build -o build/$(TARGET).exe $(SRC)

# 清理构建文件
clean:
	rm -f build/$(TARGET) build/$(TARGET).exe

# 测试编译
test:
	@echo "测试Zen-C编译..."
	@if command -v $(ZC) >/dev/null 2>&1; then \
		echo "✅ zc编译器已安装"; \
		$(ZC) --version; \
	else \
		echo "❌ 错误: zc编译器未安装"; \
		echo "请运行: make install-deps 查看安装说明"; \
		exit 1; \
	fi

# 显示帮助
help:
	@echo "Zen-C Curling Game 构建系统"
	@echo ""
	@echo "可用命令:"
	@echo "  make all      - 编译游戏 (默认)"
	@echo "  make run      - 编译并运行游戏"
	@echo "  make windows  - 编译Windows可执行文件"
	@echo "  make clean    - 清理构建文件"
	@echo "  make test     - 测试编译器安装"
	@echo "  make help     - 显示此帮助信息"
	@echo ""
	@echo "源文件结构:"
	@echo "  src/main_window.zc    - 主入口"
	@echo "  src/game_logic.zc    - 游戏逻辑"
	@echo "  src/platform_api.zc  - 平台API"

.PHONY: all run windows clean test help
