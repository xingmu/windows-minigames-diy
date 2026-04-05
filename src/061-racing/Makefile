# Makefile - Zen-C 俯视角赛车游戏
# 支持 Linux/macOS

# 编译器设置
ZENC ?= zenc
CFLAGS = -O2 -Wall

# 源文件
SRC_DIR = src
SOURCES = $(SRC_DIR)/main_window.zc $(SRC_DIR)/game_logic.zc $(SRC_DIR)/platform_api.zc

# 输出文件
OUTPUT = 061-racing

# Zen-C 框架路径
ZENFRAMEWORK = ../003-framework

.PHONY: all clean run help

all: $(OUTPUT)

$(OUTPUT): $(SOURCES)
	@echo "=========================================="
	@echo "Zen-C Racing Game - Building"
	@echo "=========================================="
	@echo "Sources:"
	@echo "  - src/main_window.zc"
	@echo "  - src/game_logic.zc"
	@echo "  - src/platform_api.zc"
	@echo "=========================================="
	@echo "Note: This requires Zen-C compiler (zenc)"
	@echo "If zenc is not installed, please install it first."
	@echo "=========================================="
	$(ZENC) build

clean:
	rm -f $(OUTPUT) *.o *.exe 2>/dev/null || true
	@echo "Cleaned."

run: $(OUTPUT)
	@echo "Running Zen-C Racing Game..."
	./$(OUTPUT)

help:
	@echo "Zen-C Racing Game - Build System"
	@echo ""
	@echo "Targets:"
	@echo "  all     - Build the game (default)"
	@echo "  clean   - Remove built files"
	@echo "  run     - Build and run the game"
	@echo "  help    - Show this help message"
	@echo ""
	@echo "Requirements:"
	@echo "  - Zen-C compiler (zenc)"
	@echo ""
	@echo "Usage:"
	@echo "  make          # Build the game"
	@echo "  make run      # Build and run"
	@echo "  make clean    # Clean build artifacts"
