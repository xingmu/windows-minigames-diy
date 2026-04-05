# 063-Boat 赛艇大赛 🛶

Zen-C 水上赛道赛艇游戏，驾驶赛艇率先到达终点获胜！

## 🎮 游戏介绍

- **游戏类型**: 竞速游戏
- **语言**: Zen-C
- **基于框架**: 003-framework
- **画面**: 2D 俯视角水面赛道

## 🏁 游戏玩法

- 操控赛艇在水上赛道中竞速
- 率先到达终点线即获胜
- 躲避障碍物（木桩、岩石）
- 与3艘AI赛艇同场竞技

## 🎮 操作说明

| 按键 | 功能 |
|------|------|
| ← → 或 A D | 左右移动 |
| 空格键 | 划船前进 |
| R | 重新开始 |

## 🛠️ 构建说明

### Windows 构建

```bash
# 使用批处理脚本
build_windows.bat

# 或使用 Makefile
make
```

### Zen-C 编译器

需要安装 Zen-C 编译器 `zc`。  
下载地址: https://github.com/z-libs/Zen-C

## 📁 项目结构

```
063-boat/
├── src/
│   ├── platform_api.zc         # 平台API
│   ├── platform_api_windows.zc  # Windows实现
│   ├── game.zc                 # 游戏框架
│   ├── game_logic.zc           # 游戏逻辑
│   └── main_window.zc          # 入口
├── build/                      # 构建输出
├── Makefile
├── build_windows.bat
└── README.md
```

## 🎨 游戏特性

- 4车道水上赛道
- 动态水面波浪效果
- 赛艇划桨动画
- 木桩障碍物
- AI对手竞速
- 实时计时系统
- 黑白格子终点线

## 📄 许可证

MIT License
