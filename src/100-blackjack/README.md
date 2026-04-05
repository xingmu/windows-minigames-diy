# Zen-C Blackjack - 二十一点游戏

基于 Zen-C 语言和 003-framework 开发的经典二十一点(Blackjack)游戏。

## 游戏特性

- **纯 Zen-C 开发** - 使用现代 Zen-C 语言编写，代码简洁优雅
- **跨平台支持** - Windows/Linux/macOS 使用同一份源代码
- **完整游戏规则** - 支持要牌、停牌、双倍、分裂、投降
- **美观的界面** - 扑克牌图形、筹码下注系统
- **6 副牌** - 使用 6 副标准扑克牌(312张)

## 游戏规则

### 基本规则

- 玩家和庄家各发两张牌
- 点数计算：A 可以是 1 点或 11 点，J/Q/K 都是 10 点
- 玩家需要在 21 点以内尽量接近 21 点
- 超过 21 点爆牌，立即输掉本局
- 庄家必须按规则要牌(小于17点必须继续)

### 操作说明

| 按钮/按键 | 功能 |
|-----------|------|
| 点击筹码 | 选择下注金额 |
| 下注并发牌 | 开始游戏 |
| H / 要牌 | 再要一张牌 |
| S / 停牌 | 停止要牌 |
| D / 双倍 | 双倍下注，只能再要一张牌 |
| P / 分裂 | 如果两张牌相同，可分成两手 |
| Q / 投降 | 放弃本局，退回一半赌注 |
| R / 新游戏 | 重新开始游戏 |

### 赔率

- 普通获胜：1:1
- 黑杰克(21点且只有2张牌)：3:2
- 投降：退回一半赌注

## 构建方法

### 前置要求

1. 安装 Zen-C 编译器：https://github.com/z-libs/Zen-C
2. 安装 GCC 编译器(Windows 下使用 MinGW)

### 编译

```bash
# Linux/macOS
make all

# Windows
build_windows.bat
```

### 运行

```bash
make run
```

### 清理

```bash
make clean
```

## 项目结构

```
src/100-blackjack/
├── Makefile              # 构建配置
├── README.md             # 本文件
├── LICENSE               # MIT 许可证
├── SECURITY.md           # 安全说明
├── build_windows.bat     # Windows 构建脚本
└── src/
    ├── main_window.zc   # 主程序(窗口、事件处理)
    ├── game_logic.zc    # 游戏逻辑(二十一点规则)
    └── platform_api.zc  # 平台 API 封装(跨平台)
```

## 技术实现

- **框架版本**：基于 003-framework
- **编程语言**：Zen-C
- **图形系统**：原生窗口 API (Windows GDI / Linux GTK / macOS Cocoa)
- **随机数**：线性同余生成器
- **牌堆管理**：6 副牌循环使用

## 许可证

MIT License - 详见 LICENSE 文件

## 致谢

- Zen-C 语言项目：https://github.com/z-libs/Zen-C
- 003-framework 游戏框架
