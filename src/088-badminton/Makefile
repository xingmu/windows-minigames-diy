# Zen-C Badminton Game Makefile
# 088-Badminton 羽毛球游戏

# Compiler settings
ZC = zc
CC = gcc
CFLAGS = -Wall -Wextra -O2
TARGET = badminton_game

# Source files
SRC = src/main_window.zc
OUT = build/$(TARGET)

# Default target
all: $(OUT)

# Compile Zen-C code
$(OUT): $(SRC)
	@mkdir -p build
	$(ZC) build -o $(OUT) $(SRC)

# Run game
run: $(OUT)
	./$(OUT)

# Clean build files
clean:
	rm -rf build/

# Install dependencies
install-deps:
	@echo "Please install zc compiler from https://github.com/z-libs/Zen-C"

# Test compilation
test:
	@echo "Testing Zen-C compilation..."
	@if command -v $(ZC) >/dev/null 2>&1; then \
		echo "✅ zc compiler is installed"; \
		$(ZC) --version; \
	else \
		echo "❌ Error: zc compiler not installed"; \
		echo "Please run: make install-deps for installation instructions"; \
		exit 1; \
	fi

# Show help
help:
	@echo "Zen-C Badminton Game Build System"
	@echo ""
	@echo "Available commands:"
	@echo "  make all      - Build game (default)"
	@echo "  make run      - Build and run game"
	@echo "  make clean    - Clean build files"
	@echo "  make test     - Test compiler installation"
	@echo "  make help     - Show this help"

.PHONY: all run clean test help install-deps
