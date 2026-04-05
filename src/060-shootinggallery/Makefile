# Makefile for Zen-C Shooting Gallery Game
# 射击训练游戏构建配置

# 项目名称
PROJECT = 060-shootinggallery
TARGET = shootinggallery

# Zen-C 编译器
ZC = zcc
ZC_FLAGS = -O2 -std=c11

# 源文件目录
SRC_DIR = src
BUILD_DIR = build

# 源文件
SOURCES = $(SRC_DIR)/main_window.zc \
          $(SRC_DIR)/game.zc \
          $(SRC_DIR)/platform_api.zc \
          $(SRC_DIR)/platform_api_windows.zc

# 输出
OUTPUT = $(BUILD_DIR)/$(TARGET)

# 默认目标
all: dirs $(OUTPUT)

# 创建构建目录
dirs:
	@mkdir -p $(BUILD_DIR)

# 链接所有编译后的 .o 文件
$(OUTPUT): $(SOURCES:.zc=.o)
	@echo "Linking $(TARGET)..."
	$(ZC) -o $(OUTPUT) $^

# 编译每个 .zc 文件
%.o : %.zc
	@echo "Compiling $<..."
	$(ZC) $(ZC_FLAGS) -c $< -o $@

# 清理
clean:
	rm -f $(BUILD_DIR)/*.o $(OUTPUT)

# 运行
run: all
	./$(OUTPUT)

# 测试编译
test:
	@echo "Testing Zen-C compiler..."
	@$(ZC) --version || echo "Zen-C compiler not found"

.PHONY: all dirs clean run test
