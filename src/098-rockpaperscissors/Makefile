# Zen-C Rock-Paper-Scissors Game Makefile
# Build system using zc compiler

# Compiler settings
ZC = zc
CC = gcc
CFLAGS = -Wall -Wextra -O2
TARGET = rockpaperscissors

# Source files - entry file is main_window.zc
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

# Install dependencies (if needed)
install-deps:
	@echo "Please install zc compiler from https://github.com/z-libs/Zen-C"

# Test compilation
test:
	@echo "Testing Zen-C compilation..."
	@if command -v $(ZC) >/dev/null 2>&1; then \
		echo "zc compiler installed"; \
		$(ZC) --version; \
	else \
		echo "Error: zc compiler not installed"; \
		exit 1; \
	fi

# Show help
help:
	@echo "Zen-C Rock-Paper-Scissors Game Build System"
	@echo ""
	@echo "Available commands:"
	@echo "  make all      - Compile game (default)"
	@echo "  make run      - Compile and run game"
	@echo "  make clean    - Clean build files"
	@echo "  make test     - Test compiler installation"
	@echo "  make help     - Show this help message"

.PHONY: all run clean test help install-deps
