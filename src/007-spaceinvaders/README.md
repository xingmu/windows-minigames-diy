# Space Invaders - 太空侵略者

Zen-C 游戏框架 v1.0.0 制作的经典太空侵略者游戏。

## 📖 游戏介绍

经典太空侵略者游戏，玩家控制飞船抵御外星入侵者。

## 🎮 游戏玩法

- 使用 **← →** 方向键移动飞船
- 使用 **空格** 发射子弹
- 按 **ESC** 退出游戏

## 👾 外星人类型

| 类型 | 颜色 | 分数 |
|------|------|------|
| Type A | 红色 | 30 分 |
| Type B | 绿色 | 20 分 |
| Type C | 蓝色 | 10 分 |

## 🏆 胜负条件

- **胜利**: 消灭所有外星人
- **失败**: 外星人到达底部或玩家被击中

## 📦 技术规格

- **语言**: Zen-C
- **框架**: 003-framework v1.0.0
- **平台**: Windows GUI
- **分辨率**: 640 x 700

## 🔧 构建

```bash
# 使用 Makefile
make

# 或使用 Windows 构建脚本
build_windows.bat
```

## 📁 项目结构

```
007-spaceinvaders/
├── src/
│   ├── platform_api.zc         # 平台API封装
│   ├── platform_api_windows.zc # Windows平台实现
│   ├── game.zc                # 游戏框架核心
│   └── main_window.zc         # 游戏主程序
├── build/                      # 构建输出
├── Makefile                   # 构建配置
├── build_windows.bat          # Windows构建脚本
└── README.md                  # 本文件
```

## 📄 许可证

MIT License
