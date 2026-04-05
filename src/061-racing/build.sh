#!/bin/bash
# build.sh - Zen-C Racing Game Build Script (Unix/Linux/macOS)

echo "=========================================="
echo "Zen-C Racing Game - Build Script"
echo "=========================================="
echo ""

# 检查 zenc 编译器
if ! command -v zenc &> /dev/null; then
    echo "[警告] 未找到 zenc 命令"
    echo ""
    echo "请安装 Zen-C 编译器"
    echo "或确保 'zenc' 已添加到 PATH"
    echo ""
    echo "编译命令:"
    echo "  zenc build"
    echo ""
    exit 1
fi

echo "[OK] Zen-C 编译器已找到"
echo ""
echo "编译源文件..."
echo "  - src/main_window.zc"
echo "  - src/game_logic.zc"
echo "  - src/platform_api.zc"
echo ""

# 执行编译
zenc build

if [ $? -eq 0 ]; then
    echo ""
    echo "=========================================="
    echo "编译成功!"
    echo "运行: ./061-racing"
    echo "=========================================="
else
    echo ""
    echo "=========================================="
    echo "[错误] 编译失败!"
    echo "=========================================="
    exit 1
fi
