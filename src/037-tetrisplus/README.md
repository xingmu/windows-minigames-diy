# TetrisPlus - 俄罗斯方块增强版 🧊

Zen-C 俄罗斯方块增强版游戏，使用 003-framework 框架开发。

## 增强特性

相比标准俄罗斯方块，TetrisPlus 增加以下特性：

### 1. 更多形状 (12种 vs 7种)
标准7种形状：
- I, O, T, S, Z, J, L

新增5种增强形状：
- **Big-I**: 5格长的I形方块
- **Small 2x2**: 2x2小方块
- **Plus**: 十字形方块
- **Big-L**: 3x3变体L形
- **Small-3**: 3格短直线

### 2. 更快速度
- 初始下落间隔: 600ms (标准500ms更快)
- 每10行升一级，速度减少40ms
- 最高速度: 50ms下落一格

### 3. 幽灵方块
- 半透明显示方块落到底部的位置
- 帮助玩家更精确地放置方块

### 4. 连击系统
- 连续消除行数获得额外加分
- Combo 奖励: 连续消除时额外50分/行

### 5. Back-to-Back Tetris
- 连续消除4行(Tetris)获得1.5倍分数
- 额外500分奖励

## 操作说明

| 按键 | 功能 |
|------|------|
| ← → | 左右移动 |
| ↑ | 旋转 |
| ↓ | 软降(加速下落) |
| 空格 | 硬降(直接落底) |
| ESC | 退出游戏 |

## 计分系统

- 单行消除: 100 × 等级
- 双行消除: 300 × 等级
- 三行消除: 500 × 等级
- Tetris(4行): 800 × 等级 + 500奖励

## 项目结构

```
037-tetrisplus/
├── src/
│   ├── main_window.zc        # 游戏主程序
│   ├── platform_api.zc      # 平台API接口
│   ├── platform_api_windows.zc # Windows实现
│   └── game.zc              # 游戏框架核心
├── build/                    # 构建输出
├── docs/
│   └── design/DESIGN.md     # 设计文档
├── Makefile
├── build_windows.bat
└── README.md
```

## 构建

### Linux/Mac
```bash
make
```

### Windows
```bash
build_windows.bat
```

## 技术栈

- **语言**: Zen-C
- **框架**: 003-framework v1.0.0
- **平台**: Windows (通过兼容层支持其他平台)

---

**作者**: ZenC开发者 🧘  
**版本**: 1.0.0  
**日期**: 2026-04-06
