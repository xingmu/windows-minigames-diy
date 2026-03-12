# Windows Mini Games DIY 🕹️

一个让你**自己动手打造**的 Windows 迷你游戏集合。

## 🎮 游戏列表

| 游戏 | 描述 | 状态 | 目录 |
|------|------|------|------|
| 🐍 贪吃蛇 | 经典贪吃蛇游戏 | ✅ 可玩 | `src/snake/` |

更多游戏陆续添加中...

## ✨ 项目特色

- **DIY 精神**: 所有代码开源，你可以自己修改、扩展
- **零依赖**: 不需要安装任何运行时，直接编译运行
- **多版本**: 控制台版 / 窗体版 可选
- **易于扩展**: 清晰的代码结构，方便添加新游戏
- **Zen-C 语言**: 核心代码使用 Zen-C 编写，仅支持 Windows 平台

## 🚀 快速开始

### 下载项目

```bash
git clone https://github.com/xingmu/windows-minigames-diy.git
cd windows-minigames-diy
```

### 编译运行

#### 贪吃蛇（控制台版）

```bash
cd build/snake/console
build_windows.bat
```

#### 贪吃蛇（窗体版）

```bash
cd build/snake/window
build_windows_window.bat
```

## 📁 项目结构

```
windows-minigames-diy/
├── src/                         # 源代码
│   ├── snake/                  # 贪吃蛇游戏
│   │   ├── console/           # 控制台版本
│   │   │   ├── game_logic.zc  # 游戏逻辑
│   │   │   └── platform_api.zc # 平台API封装
│   │   ├── window/            # 窗体版本
│   │   ├── game.json          # 游戏配置
│   │   └── README.md          # 游戏说明
│   └── common/                 # 公共代码
├── build/                       # 构建脚本
│   └── snake/
│       ├── console/            # 控制台版构建
│       └── window/             # 窗体版构建
├── docs/                        # 文档
│   └── snake/                  # 游戏文档
├── .github/                     # GitHub配置
├── README.md                    # 项目首页
└── LICENSE                      # 许可证
```

## 🛠️ 技术栈

- **语言**: Zen-C (仅支持 Windows)
- **图形**: Win32 API / Console
- **编译器**: GCC / MinGW

## ⚠️ 技术约束

- **平台限制**: 仅支持 Windows 10/11
- **开发语言**: 主代码必须使用 Zen-C 语言
- **禁止语言**: 不得使用 C++, C#, Python, Java 等其他语言

## 🤝 如何贡献

1. Fork 本项目
2. 创建分支 (`git checkout -b feature/新游戏`)
3. 提交更改 (`git commit -am '添加新游戏'`)
4. 推送分支 (`git push origin feature/新游戏`)
5. 创建 Pull Request

## 📄 许可证

MIT License - 自由使用，永久开源

---

**DIY 精神，玩转编程** 🔧
