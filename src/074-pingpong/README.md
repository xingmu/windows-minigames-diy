# 074-Pingpong 乒乓球 - 双人对战版

![Zen-C](https://img.shields.io/badge/Zen-C-游戏-blue)
![Platform](https://img.shields.io/badge/Platform-Windows-green)

## 游戏简介

074-Pingpong 是一款 **双人本地对战** 的乒乓球游戏，玩家1和玩家2在同一台电脑上对战。

**与006-Pong的区别：**
- 006-Pong：玩家 vs 电脑AI
- 074-Pingpong：玩家1 vs 玩家2（双人本地对战）

## 游戏特色

- 🎮 **双人对战**：两名玩家在同一键盘上对战
- 🎨 **独特配色**：P1青色 vs P2橙色
- ⚡ **连击系统**：记录连续击球次数
- 💥 **速度递增**：球速随每次击球增加
- ✨ **发光特效**：击球时的视觉反馈

## 操作说明

### 玩家1 (左侧)
| 按键 | 功能 |
|------|------|
| W | 向上移动 |
| S | 向下移动 |

### 玩家2 (右侧)
| 按键 | 功能 |
|------|------|
| ↑ | 向上移动 |
| ↓ | 向下移动 |

### 通用
| 按键 | 功能 |
|------|------|
| 空格 | 发球 |
| R | 重新开始 |
| ESC | 退出游戏 |

## 游戏规则

- 先到 **11分** 的玩家获胜
- 每次成功击球对方未接住，得1分
- 球速会随每次击球逐渐增加

## 构建说明

### Windows

```bash
# 使用 Makefile
make all

# 或使用批处理文件
build_windows.bat
```

### 运行游戏

```bash
make run
```

### 清理构建

```bash
make clean
```

## 技术栈

- **语言**：Zen-C
- **框架**：003-framework
- **平台**：Windows

## 项目结构

```
074-pingpong/
├── LICENSE
├── README.md
├── Makefile
├── build_windows.bat
└── src/
    ├── main_window.zc        # 游戏入口
    ├── game.zc               # 游戏框架
    ├── game_logic.zc         # 游戏逻辑
    ├── platform_api.zc       # 平台API定义
    └── platform_api_windows.zc  # Windows实现
```

## License

本项目采用 MIT 许可证 - 详见 [LICENSE](LICENSE) 文件
