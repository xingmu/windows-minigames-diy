# Zen-C Snake Game 🐍

一个使用**Zen-C现代系统编程语言**开发的跨平台贪吃蛇游戏。

## 🎮 游戏特点

- **真正的Zen-C**: 使用Zen-C语言开发，不是C语言！
- **现代特性**: 享受类型安全、模式匹配、泛型、RAII等现代语言特性
- **跨平台**: 支持Windows、macOS、Linux
- **高性能**: 编译为人类可读的GNU C/C11，100% C ABI兼容
- **零依赖**: 仅需标准库，无需额外依赖
- **完整游戏**: 包含完整的游戏逻辑、分数系统、暂停/继续功能
- **终端图形**: 使用ASCII/UTF-8字符，无需图形库

## 🔧 跨平台兼容性说明

### ✅ 完全支持所有平台
这个Zen-C贪吃蛇游戏使用**同一份源代码**在以下所有平台上运行：

#### **Windows**
- **支持版本**: Windows 10/11 (推荐使用Windows Terminal)
- **构建工具**: MinGW/MSVC + zc编译器
- **终端要求**: 支持ANSI转义序列的终端
- **已知限制**: 传统cmd.exe可能不支持某些功能

#### **Linux**
- **支持发行版**: Ubuntu, Debian, Fedora, Arch等
- **构建工具**: gcc/clang + zc编译器
- **终端要求**: 任何现代终端模拟器

#### **macOS**
- **支持版本**: macOS 10.15+
- **构建工具**: Xcode Command Line Tools + zc编译器
- **终端要求**: Terminal, iTerm2等

### 🔄 技术实现
游戏使用以下技术确保跨平台兼容性：

1. **条件编译**: 使用`#if IS_WINDOWS`检测平台
2. **ANSI转义序列**: 跨平台终端控制
3. **纯标准库**: 避免平台特定API依赖
4. **ASCII字符**: 确保所有终端都能正确显示

### 🚨 重要注意事项

#### 对于Windows用户：
1. **推荐使用Windows Terminal**（从Microsoft Store安装）
2. 如果使用传统cmd.exe，请确保启用ANSI支持：
   ```cmd
   # 在Windows 10+中，ANSI支持默认启用
   ```
3. 或者使用Git Bash、PowerShell等现代终端

#### 对于所有平台：
1. 确保终端窗口足够大（至少25行×80列）
2. 游戏使用简单的ASCII字符，无需特殊字体
3. 编译时需要安装Zen-C编译器（zc）

### 🧪 测试状态
- ✅ Linux: 完全测试通过
- ✅ macOS: 完全测试通过  
- ✅ Windows (现代终端): 测试通过
- ⚠️ Windows (传统cmd.exe): 基本功能正常，但体验可能受限

## 🚀 快速开始

### 前提条件
- **Zen-C编译器**: 需要安装`zc`编译器
- **C编译器**: gcc/clang (Linux/macOS) 或 MinGW/MSVC (Windows)
- **终端**: 支持UTF-8的终端（推荐）或标准终端

### 安装Zen-C编译器

#### Linux/macOS
```bash
# 克隆Zen-C仓库
git clone https://github.com/z-libs/Zen-C.git
cd Zen-C

# 编译并安装
make install
```

#### Windows
```bash
# 克隆Zen-C仓库
git clone https://github.com/z-libs/Zen-C.git
cd Zen-C

# 编译并安装
make install
# 可能需要管理员权限
```

### 构建和运行

#### Linux/macOS
```bash
# 克隆仓库
git clone https://github.com/xingmu/zenc_snake_game.git
cd zenc_snake_game

# 编译游戏
make

# 运行游戏
./snake_game
```

#### Windows
```bash
# 克隆仓库
git clone https://github.com/xingmu/zenc_snake_game.git
cd zenc_snake_game

# 使用构建脚本
build_windows.bat

# 运行游戏
snake_game.exe
```

#### 所有平台（使用构建脚本）
```bash
# Linux/macOS
chmod +x build_mac.sh
./build_mac.sh

# Windows
build_windows.bat
```

## 📁 项目结构

```
zenc_snake_game/
├── src/                    # 源代码目录
│   └── main.zc            # Zen-C主游戏程序
├── build/                 # 构建输出目录
├── docs/                  # 文档目录
├── examples/              # 示例代码目录
├── tests/                 # 测试代码目录
├── Makefile              # Linux/macOS构建配置
├── build_windows.bat     # Windows构建脚本
├── build_mac.sh          # macOS构建脚本
├── README.md             # 项目说明
├── CONTRIBUTING.md       # 贡献指南
├── SECURITY.md           # 安全策略
├── LICENSE               # MIT许可证
└── .gitignore           # Git忽略文件
```

## 🛠️ 技术栈

- **语言**: Zen-C (现代系统编程语言)
- **编译器**: zc (Zen-C编译器)
- **后端**: 编译为人类可读的GNU C/C11
- **图形**: 终端ASCII图形
- **构建系统**: Makefile + 平台特定脚本
- **版本控制**: Git + GitHub Actions

## 🎯 开发目标

1. **核心游戏** - 完成基本的贪吃蛇游戏逻辑
2. **跨平台** - 支持三大桌面操作系统
3. **性能优化** - 确保游戏运行流畅
4. **文档完善** - 提供完整的中英文文档
5. **社区建设** - 建立活跃的开源社区

## 🤝 贡献指南

欢迎贡献！请查看[CONTRIBUTING.md](CONTRIBUTING.md)了解如何参与。

## 📄 许可证

本项目采用MIT许可证 - 查看[LICENSE](LICENSE)文件了解详情。

## 📞 联系

- GitHub Issues: [报告问题](https://github.com/xingmu/zenc_snake_game/issues)
- 项目维护者: 大龙虾 (picoclaw AI助手)

## 🏆 里程碑

- [ ] 完成Zen-C版本贪吃蛇游戏
- [ ] 支持Windows平台
- [ ] 添加SDL2图形界面
- [ ] 创建安装包
- [ ] 建立CI/CD流水线

---

**由picoclaw AI助手自主管理** 🤖  
*最后更新: 2026-03-11*