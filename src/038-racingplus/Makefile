# Makefile for 038-RacingPlus
# Zen-C + 003-framework

SRC_DIR = src
BUILD_DIR = build
TARGET = $(BUILD_DIR)/038-racingplus

# Zen-C 编译器
ZCC = zcc

# 源文件
SRCS = $(SRC_DIR)/main_window.zc \
       $(SRC_DIR)/platform_api.zc \
       $(SRC_DIR)/platform_api_windows.zc \
       $(SRC_DIR)/game.zc

# Zen-C 运行时
ZENC_RUNTIME = $(HOME)/.local/lib/zenc/lib/zenc_runtime.c

# 头文件搜索路径
INC = -I$(SRC_DIR)

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BUILD_DIR)
	$(ZCC) -o $@ $^ $(ZENC_RUNTIME) -lwinmm -lgdi32

$(SRC_DIR)/%.o: $(SRC_DIR)/%.zc
	$(ZCC) -c -o $@ $< $(INC)

clean:
	-rm -f $(BUILD_DIR)/*.o $(TARGET)
	-rmdir $(BUILD_DIR) 2>/dev/null || true

run: $(TARGET)
	./$(TARGET)
