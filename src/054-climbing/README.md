# Climbing - Zen-C

![Zen-C](https://img.shields.io/badge/Zen-C-1.0.0-blue)
![Platform](https://img.shields.io/badge/Platform-Windows%20GUI-green)
![License](https://img.shields.io/badge/License-MIT-yellow)

经典攀岩游戏，使用 Zen-C 语言开发，Windows GUI 版本。控制攀岩者向上攀爬，抓住岩壁上的手柄，不断攀升！

## 🎮 游戏截图

游戏运行后显示深蓝色渐变夜空背景，攀岩者在岩壁上向上攀爬，金色的手柄点缀在岩壁上。

## 📋 游戏规则

- 攀岩者受重力影响会自然下落
- 按 **空格键** 或 **上箭头** 或 **鼠标点击** 抓住最近的手柄
- 松开按键释放手柄，攀岩者会获得一个向上的跳跃力
- 按 **左/右方向键** 控制攀爬者在岩壁上的水平移动
- 不断向上攀爬，挑战更高的高度！
- 掉出屏幕底部游戏结束

## 🎯 操作说明

| 按键 | 功能 |
|------|------|
| 空格 / 上箭头 / 鼠标左键 | 抓住手柄 |
| 左箭头 | 向左移动 |
| 右箭头 | 向右移动 |
| ESC | 退出游戏 |

## 🚀 快速开始

### Windows

1. 双击 `build_windows.bat` 编译并运行
2. 或手动编译:
   ```bash
   zc build -o build/climbing.exe src/main_window.zc
   ./build/climbing.exe
   ```

### Linux (需要 Zen-C 环境)

```bash
make
make run
```

## 📁 项目结构

```
054-climbing/
├── src/
│   ├── main_window.zc        # 游戏主程序
│   └── platform_api.zc       # 平台 API 接口
├── build/                    # 编译输出目录
├── Makefile                  # Linux/macOS 构建脚本
├── build_windows.bat        # Windows 构建脚本
├── README.md                # 本文件
└── docs/                    # 文档目录 (待添加)
```

## 🎨 游戏特性

- **渐变夜空背景** - 深蓝色渐变营造攀岩氛围
- **动态岩壁纹理** - 随机生成的岩石纹理
- **实时高度计** - 显示当前攀爬高度和得分
- **状态指示器** - 显示攀爬者当前状态（攀爬中/下落）
- **游戏结束统计** - 显示最高高度和最终得分

## 🔧 开发

### 技术栈

- Zen-C 语言
- Windows GUI (直接帧缓冲绘制)
- 面向对象游戏架构

### 扩展游戏

修改 `src/main_window.zc` 中的配置常量可以调整游戏难度:

```zen-c
const CLIMBER_SPEED_X = 200;      // 水平移动速度
const CLIMBER_FALL_SPEED = 400;   // 下落速度
const HANDHOLD_INTERVAL_Y = 80;   // 手柄垂直间距
const SCROLL_SPEED = 60;           // 滚动速度
```

## 📜 许可证

MIT License - 自由使用、修改和分发

---

**享受攀岩的乐趣！** 🧗‍♂️
