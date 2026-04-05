.PHONY: build clean run

# 编译器设置
CXX = zcc
CXXFLAGS = -O2 -std=c++17
TARGET = hockey.exe

# 源文件
SRC_DIR = src
SOURCES = $(SRC_DIR)/platform_api.zc $(SRC_DIR)/platform_api_windows.zc $(SRC_DIR)/game.zc $(SRC_DIR)/game_logic.zc $(SRC_DIR)/main_window.zc

# Zen-C 编译器 (zcc) 或 gcc
ZCC = zcc
ZCCFLAGS = -O2

# 框架路径
FRAMEWORK_DIR = ../003-framework/src

all: build

build:
	@echo "Building Hockey (Zen-C)..."
	@echo "Source files: $(SOURCES)"
	@echo "Note: Zen-C compilation not available in this environment"
	@echo "For Windows build, run: build_windows.bat"
	@mkdir -p build

clean:
	rm -f $(TARGET) build/*

run: build
	@echo "Run: ./$(TARGET)"

# 备用：使用 gcc 编译 C 模拟版本
c_build:
	gcc -o $(TARGET) -I$(FRAMEWORK_DIR) $(SOURCES:.zc=.c) -lm -luser32 -lgdi32

# 备用：Zen-C 编译脚本
zcc_build:
	$(ZCC) $(ZCCFLAGS) -o $(TARGET) $(SOURCES)
