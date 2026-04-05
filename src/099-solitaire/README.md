# Zen-C 纸牌接龙 🃏

一个使用 **Zen-C 现代系统编程语言** 开发的 Windows 纸牌接龙游戏(Klondike Solitaire)。

## 🎮 游戏特点

- **经典纸牌接龙**: 完整的 Klondike Solitaire 规则
- **Zen-C 原生开发**: 使用 Zen-C 源代码开发的原生 Windows 窗体游戏
- **现代特性**: 享受类型安全、模式匹配、泛型、RAII 等现代语言特性
- **高性能**: 编译为人类可读的 GNU C/C11，100% C ABI 兼容
- **完整游戏**: 包含完整的游戏逻辑、胜负判定、统计信息
- **美观界面**: 彩色纸牌图形，专业 UI 设计

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
cd windows-minigames-diy/src/099-solitaire

# 使用构建脚本
build_windows.bat

# 或者使用命令行
mkdir build
zc build -o build/solitaire src/main_window.zc
./build/solitaire.exe
```

## 🎯 游戏规则

### 基本规则

1. **目标**: 将所有52张牌移动到4个花色堆中，从A到K依次叠放
2. **牌库**: 左上角的牌堆，点击翻牌
3. **弃牌堆**: 翻出的牌放在这里，每回合可以使用1张
4. **游戏牌堆**: 7列纸牌，每列第一张翻开
5. **花色堆**: 4个位置，分别对应红桃、黑桃、梅花、方块

### 移动规则

- **游戏牌堆**: 必须交替颜色、数字递减（如：红桃7放在黑桃8上）
- **花色堆**: 只能按同一花色、递增顺序叠放（A在底部，K在顶部）
- **空位**: 只能放置K（或K开头的序列）
- **一次移动**: 可以移动一列牌，但只能移动连续正面朝上的牌

### 操作方法

- **点击**: 选择/移动纸牌
- **双击**: 自动将牌移动到花色堆
- **空格键**: 从牌库翻牌
- **N键**: 开始新游戏
- **ESC**: 退出游戏

## 📁 项目结构

```
099-solitaire/
├── src/                    # 源代码目录
│   ├── main_window.zc     # 主入口（窗口、事件处理）
│   ├── game_logic.zc      # 游戏逻辑模块
│   └── platform_api.zc    # 平台API封装
├── build/                 # 构建输出目录
├── build_windows.bat      # Windows 构建脚本
├── Makefile              # 构建配置
├── README.md             # 项目说明
├── SECURITY.md           # 安全策略
├── LICENSE               # MIT 许可证
└── .gitignore           # Git 忽略文件
```

## 📄 许可证

本项目采用 MIT 许可证 - 查看 [LICENSE](LICENSE) 文件了解详情。

## 📞 联系

- GitHub Issues: [报告问题](https://github.com/xingmu/windows-minigames-diy/issues)

---

**由 ZenC开发者 AI 助手自主管理** 🤖  
*最后更新: 2026-04-06*
