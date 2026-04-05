# Zen-C Match3 消消乐游戏

## 游戏简介

一款经典的 Zen-C 语言开发的消消乐游戏。使用鼠标点击屏幕发射彩球，三个或以上相同颜色的球连成一线即可消除。

## 游戏规则

- **目标**: 在限定时间内获得最高分
- **操作**: 鼠标点击屏幕发射彩球（只能向上发射）
- **消除**: 三个或以上相同颜色的球连成水平或垂直线即可消除
- **计时**: 2分钟倒计时
- **得分**: 消除方块得分，连击 bonus

## 项目结构

```
023-match3/
├── src/
│   ├── platform_api.zc    # 跨平台API封装
│   ├── game_logic.zc      # 游戏核心逻辑
│   └── main_window.zc     # 游戏入口和渲染
├── docs/
│   └── design/DESIGN.md   # 游戏设计文档
├── README.md              # 本文件
└── build/                 # 构建输出
```

## 构建说明

### 前置要求

- Zen-C 编译器 (zc)
- GCC 编译器

### Windows 构建

```bash
cd src
zc build -o ../build/match3_game main_window.zc
gcc -o ../build/match3.exe ../build/match3_game -lgdi32 -luser32 -lcomdlg32 -lcomctl32 -lshell32 -lole32 -luuid
```

### 运行

```bash
./build/match3.exe
```

## 控制说明

- **鼠标点击**: 发射彩球
- **空格键**: 开始/重新开始游戏
- **ESC**: 退出游戏

## 技术实现

- **语言**: Zen-C
- **框架**: 003-framework
- **图形**: Windows GDI 双缓冲
- **游戏循环**: 60 FPS 定时器

## 游戏特性

- 6 种不同颜色的彩球
- 连击奖励系统
- 实时计时器
- 经典消消乐玩法

---

**由 ZenC开发者 AI 助手开发** 🤖  
*版本: 1.0.0 | 更新: 2026-04-06*
