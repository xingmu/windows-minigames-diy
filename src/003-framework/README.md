# Zen-C 游戏框架 v1.0.0 💻

Windows 小游戏开发的基础框架，提供统一的窗口管理、绘图接口和游戏循环。

## 📦 框架概述

- **版本**: 1.0.0
- **目标**: 为 001-100 所有小游戏提供统一开发基础
- **语言**: Zen-C 现代系统编程语言

## 🏗️ 项目结构

```
003-framework/
├── src/
│   ├── platform_api.zc         # 统一平台接口定义
│   ├── platform_api_windows.zc # Windows 平台实现
│   ├── game.zc                # 游戏核心类 (Game, Canvas)
│   └── main_window.zc         # 入口点 + 示例代码
├── docs/
│   └── framework/             # 框架设计文档
├── build/                     # 构建输出
└── README.md                   # 本文件
```

## 🎮 快速开始

### 创建新游戏

```bash
# 克隆框架
cd windows-minigames-diy/src
cp -r 003-framework 004-mygame
cd 004-mygame
```

### 实现游戏逻辑

1. 创建游戏类继承 `Game`
2. 重写必要的方法
3. 编译运行

```zen-c
import "platform_api.zc";
import "game.zc";

// 贪吃蛇游戏示例
class SnakeGame extends Game {
    // 游戏数据...
    
    fn onInit() {
        // 初始化
    }
    
    fn onUpdate(dt: u32) {
        // 游戏逻辑
    }
    
    fn onRender(canvas: Canvas) {
        // 绘制画面
    }
}

fn main() {
    var game = SnakeGame.("Snake", 640, 480, 60);
    game.run();
    game.destroy();
}
```

## 📚 核心 API

### Game 类

游戏主类，所有游戏都继承自此类。

```zen-c
// 创建游戏
var game = Game.("游戏标题", 宽度, 高度, 帧率);

// 游戏状态
game.getState()     // 获取状态 (Ready/Playing/Paused/Won/Lost)
game.setState(状态) // 设置状态
game.stop()         // 停止游戏
game.getScore()     // 获取分数
game.addScore(分数) // 添加分数
```

### 必须重写的方法

```zen-c
fn onInit()           // 初始化游戏数据
fn onShutdown()       // 清理资源
fn onUpdate(dt: u32)  // 每帧更新逻辑 (dt=毫秒)
fn onRender(canvas)   // 每帧绘制画面
```

### 可选重写的方法

```zen-c
fn onKeyDown(key)     // 键盘按下
fn onKeyUp(key)       // 键盘释放
fn onMouseDown(x,y,b) // 鼠标按下
fn onMouseUp(x,y,b)   // 鼠标释放
```

### Canvas 画布

提供基本绘图功能。

```zen-c
// 清屏
canvas.clear(Color.Black());

// 像素
canvas.setPixel(x, y, Color.Red());

// 线条
canvas.drawLine(x1, y1, x2, y2, Color.White());

// 矩形 (描边/填充)
canvas.drawRect(x, y, w, h, Color.Blue());
canvas.fillRect(x, y, w, h, Color.Green());

// 圆形 (描边/填充)
canvas.drawCircle(cx, cy, radius, Color.Yellow());
canvas.fillCircle(cx, cy, radius, Color.Cyan());

// 文字
canvas.drawText(x, y, "Hello", Color.White(), Font.("Arial", 16));

// 尺寸
canvas.getWidth();
canvas.getHeight();
```

### Color 颜色

```zen-c
Color.Black()    // 黑色
Color.White()    // 白色
Color.Red()      // 红色
Color.Green()    // 绿色
Color.Blue()     // 蓝色
Color.RGB(r,g,b) // 自定义 RGB
```

### VirtualKey 键码

```zen-c
VirtualKey.Escape  // ESC
VirtualKey.Space    // 空格
VirtualKey.Enter    // 回车
VirtualKey.Left/Up/Right/Down  // 方向键
VirtualKey.Key0-9   // 数字键
VirtualKey.F1-F12   // 功能键
```

### MouseButton 鼠标

```zen-c
MouseButton.Left   // 左键
MouseButton.Right  // 右键
MouseButton.Middle // 中键
```

### GameState 游戏状态

```zen-c
GameState.Ready   // 等待开始
GameState.Playing // 游戏中
GameState.Paused  // 暂停
GameState.Won     // 胜利
GameState.Lost    // 失败
```

## 📐 游戏模板

每个子项目应遵循以下模板结构：

```
xxx-gamename/
├── src/
│   ├── platform_api.zc    # 从003-framework复制
│   ├── platform_api_windows.zc
│   ├── game.zc
│   ├── main_window.zc    # 游戏入口
│   └── (其他游戏模块)
├── docs/
│   └── design/DESIGN.md  # 游戏设计文档
├── build/                 # 构建输出
├── Makefile              # 构建配置
├── build_windows.bat     # Windows 构建
└── README.md             # 项目说明
```

## 🔧 构建说明

### Zen-C 编译器

需要安装 Zen-C 编译器 `zc`。

### Windows 构建

```bash
# 使用构建脚本
build_windows.bat

# 或使用 Makefile
make
```

## 📄 许可证

本项目采用 MIT 许可证 - 查看 [LICENSE](../../LICENSE) 文件了解详情。

---

**由 ZenC开发者 AI 助手自主管理** 🤖  
*框架版本: 1.0.0 | 最后更新: 2026-04-05*
