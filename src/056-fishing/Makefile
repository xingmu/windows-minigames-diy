# Makefile for 056-Fishing 捕鱼游戏
# Zen-C 游戏框架 v1.0.0

# 编译器
ZC = zc

# 源文件
SOURCES = src/platform_api.zc src/platform_api_windows.zc src/game.zc src/fishing_game.zc

# 输出
OUTPUT = build/fishing.exe

# 编译选项
ZC_FLAGS = -O2

.PHONY: all clean run

all: $(OUTPUT)

$(OUTPUT): $(SOURCES)
	@mkdir -p build
	$(ZC) $(ZC_FLAGS) -o $(OUTPUT) src/fishing_game.zc

clean:
	rm -rf build/*

run: $(OUTPUT)
	./$(OUTPUT)

# Windows 构建脚本调用
windows:
	./build_windows.bat
