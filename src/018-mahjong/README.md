# Zen-C 麻将游戏 🀄

一个使用 **Zen-C 现代系统编程语言** 开发的 Windows 麻将游戏。

## 🎮 游戏特点

- **经典麻将玩法**: 完整实现麻将牌型（万子、筒子、索子、风牌、三元牌）
- **玩家 vs 电脑AI**: 三位电脑玩家，智能出牌
- **吃碰杠胡判定**: 完整的吃、碰、杠、胡牌判定逻辑
- **标准规则**: 基于经典麻将规则
- **精美界面**: 彩色牌面、游戏区域、信息面板

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
cd windows-minigames-diy/src/018-mahjong

# 使用构建脚本
build_windows.bat

# 运行游戏
mahjong_game.exe
```

## 🎯 操作说明

| 操作 | 功能 |
|------|------|
| 鼠标左键 | 选择手牌/点击按钮 |
| 鼠标右键 | 打出选中的牌 |
| ← → | 选择手牌 |
| Enter/Space | 确认选择/打出牌 |
| ESC | 退出游戏 |

## 🀄 麻将规则

### 牌型

- **万子**: 一万～九万
- **筒子**: 一筒～九筒  
- **索子**: 一条～九条
- **风牌**: 东南西北
- **三元牌**: 红中、发财、白板

### 操作

- **吃**: 只能吃下家打出的牌，组成顺子
- **碰**: 任意玩家打出牌，手牌中有2张相同可碰
- **杠**: 手牌中有3张相同可杠（明杠/加杠）
- **胡**: 满足胡牌条件（4组面子+1对将）

### 胡牌条件

手牌必须满足: **4个面子 + 1个将牌**
- 面子可以是: 顺子(3张连续)、刻子(3张相同)
- 将牌是: 1对相同的牌

## 📊 AI 难度

游戏提供三个难度级别的AI:

| 级别 | 说明 |
|------|------|
| 简单 | 随机出牌 |
| 普通 | 避免放炮，优先打孤张 |
| 困难 | 优化胡牌机会，考虑牌组关联 |

## 📁 项目结构

```
018-mahjong/
├── src/
│   ├── main_window.zc              # 主程序（游戏逻辑）
│   ├── mahjong_logic.zc            # 麻将核心逻辑
│   ├── platform_api.zc             # 平台API
│   ├── platform_api_windows.zc    # Windows平台实现
│   └── game.zc                     # 游戏框架
├── docs/design/                    # 设计文档
├── build/                          # 构建输出目录
├── build_windows.bat              # Windows构建脚本
├── Makefile                        # 构建配置
├── README.md                       # 项目说明
├── LICENSE                        # MIT许可证
└── .gitignore                     # Git忽略文件
```

## 🏗️ 技术架构

- **框架**: 003-framework
- **基类**: Game（提供窗口管理、事件循环、画布接口）
- **游戏逻辑**: MahjongGame 类，继承 Game
- **核心算法**:
  - 牌墙管理（洗牌、发牌、摸牌）
  - 胡牌判定（面子+将牌算法）
  - 吃碰杠判定
  - AI决策（多难度级别）

## 📄 许可证

本项目采用 MIT 许可证 - 查看 [LICENSE](LICENSE) 文件了解详情。

## 📞 联系

- GitHub Issues: [报告问题](https://github.com/xingmu/windows-minigames-diy/issues)

---

**由 ZenC开发者 AI 助手自主管理** 🤖  
*最后更新: 2026-04-06*
