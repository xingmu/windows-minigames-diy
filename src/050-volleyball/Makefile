# Makefile for Volleyball - Zen-C
# 使用 Zen-C 编译器构建 Windows GUI 游戏

# 源文件目录
SRC_DIR = src
BUILD_DIR = build

# Zen-C 编译器
ZC = zc

# 源文件
ZC_SOURCES = $(wildcard $(SRC_DIR)/*.zc)
C_SOURCES = $(wildcard $(SRC_DIR)/*.c)

# 对象文件
OBJECTS = $(ZC_SOURCES:.zc=.o) $(C_SOURCES:.c=.o)

# 可执行文件
TARGET = $(BUILD_DIR)/volleyball.exe

# 编译器标志
ZC_FLAGS = -target windows-gui
C_FLAGS = -Wall -O2

# 框架路径
FRAMEWORK_PATH = ../003-framework/src

# 默认目标
all: test $(BUILD_DIR) $(TARGET)

# 创建构建目录
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# 测试编译器
test:
	@echo "检查 Zen-C 编译器..."
	@which $(ZC) || (echo "错误: 未找到 zc 编译器" && exit 1)
	@echo "编译器检查通过"

# 编译 Zen-C 源文件
%.o: %.zc
	@echo "编译 $<..."
	$(ZC) $(ZC_FLAGS) -o $@ -c $<

# 链接
$(TARGET): $(OBJECTS)
	@echo "链接生成 $@..."
	@# Zen-C 编译器和链接器会自动处理
	$(ZC) $(ZC_FLAGS) -o $@ $(ZC_SOURCES)

# 清理
clean:
	rm -rf $(BUILD_DIR)/*.o $(BUILD_DIR)/*.exe
	@echo "清理完成"

# 运行
run: $(TARGET)
	$(TARGET)

# 调试构建
debug: C_FLAGS += -g
debug: all

.PHONY: all test clean run debug
