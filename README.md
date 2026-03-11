# Zen-C Snake Game 🐍

一个使用Zen-C现代系统编程语言开发的跨平台贪吃蛇游戏。

## 🎮 游戏特点

- **现代语言**: 使用Zen-C开发，享受类型安全、模式匹配、泛型等现代特性
- **跨平台**: 支持Windows、macOS、Linux
- **高性能**: 编译为人类可读的GNU C/C11，100% C ABI兼容
- **零依赖**: 仅需标准库，无需额外依赖
- **完整游戏**: 包含完整的游戏逻辑、分数系统、暂停/继续功能

## 🚀 快速开始

### 前提条件
- Zen-C编译器 (`zc`)
- 或C编译器 (gcc/clang) 用于C版本

### 构建和运行

```bash
# 使用Zen-C编译器
zc build

# 或使用C编译器
make
./snake_game
```

## 📁 项目结构

```
zenc_snake_game/
├── src/           # 源代码目录
│   ├── main.zc    # Zen-C主程序
│   ├── game.zc    # 游戏逻辑
│   └── render.zc  # 渲染模块
├── build/         # 构建配置
│   ├── Makefile   # Linux/macOS构建
│   ├── build_windows.bat  # Windows构建
│   └── build_mac.sh       # macOS构建
├── docs/          # 文档
├── examples/      # 示例代码
└── tests/         # 测试代码
```

## 🛠️ 技术栈

- **语言**: Zen-C (编译为C)
- **图形**: 终端ASCII图形 / SDL2可选
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