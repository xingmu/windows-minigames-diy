# Zen-C Baseball Game ⚾

一个使用 **Zen-C 现代系统编程语言** 开发的 Windows 棒球游戏。

## 🎮 游戏特点

- **Zen-C 窗体版本**: 使用 Zen-C 源代码开发的原生 Windows 窗体游戏
- **现代特性**: 享受类型安全、模式匹配、泛型、RAII 等现代语言特性
- **高性能**: 编译为人类可读的 GNU C/C11，100% C ABI 兼容
- **完整游戏**: 包含完整的棒球规则、好坏球、出局、局数计算
- **美观界面**: 彩色图形界面，专业 UI 设计

## 🚀 快速开始

### 前提条件

- **Zen-C 编译器**: 需要安装 `zc` 编译器
- **C 编译器**: MinGW 或 MSVC (Windows)
- **操作系统**: Windows 10/11

### 安装 Zen-C 编译器

```bash
# 克隆 Zen-C 仓库
git clone https://github.com/z-libs/Zen-C.git
cd Zen-C

# 编译并安装
make install
# 可能需要管理员权限
```

### 构建和运行

```bash
# 克隆仓库
git clone https://github.com/xingmu/windows-minigames-diy.git
cd windows-minigames-diy/src/078-baseball

# 使用构建脚本
build_windows.bat

# 运行游戏
baseball_game.exe
```

## 📁 项目结构

```
078-baseball/
├── src/                    # 源代码目录
│   ├── main_window.zc     # 主入口（窗口、事件处理）
│   ├── BaseballGame.zc     # 游戏逻辑模块
│   ├── platform_api.zc    # 平台API封装
│   ├── platform_api_windows.zc # Windows 平台实现
│   └── game.zc            # 框架核心
├── build/                  # 构建输出目录
├── build_windows.bat      # Windows 构建脚本
├── Makefile              # 构建配置
├── README.md             # 项目说明
├── SECURITY.md           # 安全策略
├── LICENSE               # MIT 许可证
└── .gitignore           # Git 忽略文件
```

## 🎯 游戏规则

### 基本规则

- **9局比赛**: 客队先攻，主队后攻
- **3出局换局**: 每局有3个出局
- **好球区**: 本垒板周围的矩形区域
- **好坏球**: 4个坏球保送，3个好球三振

### 计分

- **全垒打**: 球飞到外场边界外得1分
- **安打**: 击球成功可能上垒

### 击球控制

- **左键点击**: 挥棒击球
- **力量**: 由鼠标Y位置决定（越高力量越大）
- **时机**: 由鼠标X位置决定（越接近本垒中心时机越好）

## 🎮 操作说明

| 按键 | 功能 |
|------|------|
| 空格 | 开始游戏 / 继续 / 重新开始 |
| 左键 | 挥棒击球 |
| A | 切换自动游玩模式 |

## 📄 许可证

本项目采用 MIT 许可证 - 查看 [LICENSE](LICENSE) 文件了解详情。

## 📞 联系

- GitHub Issues: [报告问题](https://github.com/xingmu/windows-minigames-diy/issues)

---

**由 ZenC开发者 AI 助手自主管理** 🤖  
*最后更新: 2026-04-06*
