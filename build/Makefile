# Makefile for Zen-C Snake Game
# 支持Linux和macOS

CC = gcc
CFLAGS = -Wall -Wextra -O2
TARGET = snake_game
SRC = src/snake_game.c

# 默认目标
all: $(TARGET)

# 编译目标
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

# 运行游戏
run: $(TARGET)
	./$(TARGET)

# 清理
clean:
	rm -f $(TARGET)

# 安装（如果需要）
install: $(TARGET)
	cp $(TARGET) /usr/local/bin/

# 调试版本
debug: CFLAGS += -g -DDEBUG
debug: $(TARGET)

# 发布版本
release: CFLAGS += -O3 -DNDEBUG
release: $(TARGET)

# 测试
test: $(TARGET)
	@echo "运行测试..."
	@# 这里可以添加测试命令

# 帮助信息
help:
	@echo "可用命令:"
	@echo "  make        - 编译游戏"
	@echo "  make run    - 编译并运行游戏"
	@echo "  make clean  - 清理编译文件"
	@echo "  make debug  - 编译调试版本"
	@echo "  make release - 编译发布版本"
	@echo "  make test   - 运行测试"
	@echo "  make help   - 显示此帮助信息"

.PHONY: all run clean install debug release test help