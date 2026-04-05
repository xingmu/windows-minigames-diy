# 020-SuperMario - Zen-C 超级玛丽风格游戏

经典横版平台跳跃游戏，使用 Zen-C 和 003-framework 开发。

## 游戏特性

- **经典玩法**: 踩敌人、吃金币、跳平台
- **流畅操控**: ← → 移动，空格跳跃
- **卡通风格**: 色彩鲜艳的像素风画面
- **关卡设计**: 多层次平台 + 敌人 + 金币

## 操作说明

| 按键 | 功能 |
|------|------|
| ← | 向左移动 |
| → | 向右移动 |
| 空格/↑ | 跳跃 |
| ESC | 退出游戏 |

## 游戏目标

1. 踩死敌人获得分数
2. 收集金币获得分数
3. 每吃5个金币获得额外生命
4. 到达终点城堡获得胜利

## 项目结构

```
020-supermario/
├── src/
│   ├── main_window.zc        # 游戏主程序
│   ├── platform_api.zc       # 平台API定义
│   ├── platform_api_windows.zc # Windows实现
│   └── game.zc               # 框架核心
├── docs/
│   └── design/DESIGN.md      # 游戏设计文档
├── Makefile
├── build_windows.bat
└── README.md
```

## 构建说明

### Windows

```bash
# 使用批处理脚本
build_windows.bat

# 或使用 Makefile
make
```

### Zen-C 编译器

需要安装 Zen-C 编译器 `zc`。

## 开发

基于 003-framework 框架开发，继承统一窗口管理、绘图接口和游戏循环。

## 许可证

MIT License
