# FlappyBird 游戏设计文档

## 1. 概述

### 游戏名称
FlappyBird - Zen-C

### 游戏类型
横版过关游戏

### 版本
1.0.0

### 目标平台
Windows GUI

### 核心玩法
控制小鸟穿越管道间隙，获得尽可能高的分数。

---

## 2. 技术规格

### 开发语言
Zen-C

### 依赖框架
003-framework (Zen-C 游戏框架)

### 窗口配置
| 参数 | 值 |
|------|-----|
| 窗口宽度 | 400 像素 |
| 窗口高度 | 600 像素 |
| 目标帧率 | 60 FPS |

### 编译要求
- Zen-C 编译器 (`zc`)
- GCC 编译器 (MinGW)

---

## 3. 游戏元素

### 3.1 小鸟 (Bird)

| 属性 | 值 |
|------|-----|
| X 坐标 | 80 (固定) |
| 初始 Y 坐标 | 窗口高度 / 2 |
| 半径 | 15 像素 |
| 颜色 | RGB(255, 230, 50) 黄色 |
| 翅膀颜色 | RGB(220, 200, 40) 深黄色 |
| 嘴巴颜色 | RGB(255, 150, 50) 橙色 |

**物理参数:**
| 参数 | 值 | 说明 |
|------|-----|------|
| 重力 | 800 px/s² | 每秒下落速度增量 |
| 跳跃速度 | -350 px/s | 负值表示向上 |

**视觉效果:**
- 身体: 黄色圆形
- 眼睛: 白色圆形 + 黑色瞳孔
- 嘴巴: 橙色矩形
- 翅膀: 根据速度上下摆动

### 3.2 管道 (Pipe)

| 属性 | 值 |
|------|-----|
| 宽度 | 60 像素 |
| 间隙高度 | 150 像素 |
| 移动速度 | 180 px/s |
| 颜色 | RGB(50, 200, 80) 绿色 |
| 边缘颜色 | RGB(40, 160, 60) 深绿色 |

**管道生成:**
- 初始间隔: 1800 毫秒
- 间隙 Y 坐标: 随机 (50 ~ 窗口高度 - 80)
- 最大同时管道数: 10

### 3.3 背景

| 元素 | 颜色 |
|------|------|
| 天空 | RGB(135, 206, 250) 浅蓝色 |
| 地面 | RGB(100, 200, 100) 绿色 |

---

## 4. 游戏状态

### 状态机

```
Ready ──[空格/上箭头]──> Playing ──[碰撞]──> GameOver
  ^                              │
  └────────[空格/上箭头]──────────┘
```

### 状态说明

| 状态 | 说明 | 渲染 |
|------|------|------|
| Ready | 等待玩家开始 | 显示标题和开始提示 |
| Playing | 游戏进行中 | 正常游戏画面 |
| GameOver | 游戏结束 | 显示结束画面和分数 |

---

## 5. 计分系统

### 计分规则
- 小鸟成功穿越管道间隙: **+1 分**
- 穿越判定: 管道左侧通过小鸟 (pipe.x + pipe.width < bird.x)

### 分数显示
- 位置: 窗口顶部中央
- 格式: "分数: X"
- 颜色: 白色

---

## 6. 碰撞检测

### 碰撞类型

#### 6.1 管道碰撞
条件: 小鸟在管道水平范围内且不在间隙内
```
if bird.x + bird.radius > pipe.x && 
   bird.x - bird.radius < pipe.x + pipe.width:
    if bird.y - bird.radius < gapTop ||
       bird.y + bird.radius > gapBottom:
        -> 碰撞
```

#### 6.2 边界碰撞
- 上边界 (y < 0): 小鸟 Y 固定为 radius，速度归零
- 下边界 (y > height - 40): 游戏结束

---

## 7. 输入控制

### 键盘输入

| 按键 | 功能 | 状态 |
|------|------|------|
| 空格 | 跳跃/重新开始 | 所有状态 |
| 上箭头 | 跳跃/重新开始 | 所有状态 |
| ESC | 退出游戏 | 所有状态 |

### 鼠标输入

| 按键 | 功能 | 状态 |
|------|------|------|
| 左键 | 跳跃/重新开始 | 所有状态 |

---

## 8. 游戏循环

### 主循环 (60 FPS)

```
while running:
    1. processEvents()      # 处理窗口事件
    2. updateGame(dt)       # 更新游戏逻辑
    3. render()             # 渲染画面
    4. frameLimit()         # 帧率控制 (~16.67ms)
```

### 更新逻辑

```
updateGame(dt):
    if state != Playing: return
    
    // 1. 应用重力
    birdVelocity += GRAVITY * dt
    birdY += birdVelocity * dt
    
    // 2. 边界检查
    if birdY < RADIUS: birdY = RADIUS, velocity = 0
    if birdY > HEIGHT - 40: GameOver
    
    // 3. 生成管道
    if time - lastSpawn > SPAWN_INTERVAL:
        spawnPipe()
    
    // 4. 更新管道位置
    for each pipe:
        pipe.x -= PIPE_SPEED * dt
        if pipe.x < -PIPE_WIDTH: remove pipe
        if pipe passed bird: score++, pipe.passed = true
    
    // 5. 碰撞检测
    for each pipe:
        if collision(bird, pipe): GameOver
```

---

## 9. 数据结构

### 全局游戏状态
```zen-c
static mut window: WindowHandle
static mut running: bool
static mut gameState: GameState
static mut birdY: float
static mut birdVelocity: float
static mut pipes: [10]Pipe
static mut pipeCount: int
static mut lastPipeSpawn: u32
static mut gameTime: u32
static mut score: int
```

### Pipe 结构
```zen-c
struct Pipe {
    x: int;      // 管道左侧位置
    gapY: int;   // 间隙中心 Y 坐标
    passed: bool; // 是否已通过
}
```

---

## 10. 文件结构

```
008-flappybird/
├── src/
│   ├── main_window.zc           # 游戏主程序 (所有代码)
│   ├── platform_api.zc         # 平台 API 接口定义
│   ├── platform_api_windows.zc # Windows 平台实现
│   └── game.zc                 # 框架参考实现
├── docs/
│   └── design/
│       └── DESIGN.md            # 本文档
├── build/                       # 构建输出目录
├── Makefile                     # Make 构建配置
├── build_windows.bat           # Windows 构建脚本
└── README.md                    # 项目说明
```

---

## 11. 视觉设计

### 颜色方案
| 元素 | 颜色 | RGB |
|------|------|-----|
| 天空背景 | 浅蓝色 | (135, 206, 250) |
| 地面 | 绿色 | (100, 200, 100) |
| 小鸟身体 | 黄色 | (255, 230, 50) |
| 小鸟翅膀 | 深黄色 | (220, 200, 40) |
| 小鸟嘴巴 | 橙色 | (255, 150, 50) |
| 管道主体 | 绿色 | (50, 200, 80) |
| 管道边缘 | 深绿色 | (40, 160, 60) |
| 文字 | 白色 | (255, 255, 255) |
| 分数 | 白色 | (255, 255, 255) |

### 界面布局
```
┌────────────────────────────────────┐
│           分数: 0                  │  <- 顶部居中
│                                    │
│    ○                    ┌────┐    │
│   /█\       →    →      │    │    │  <- 管道间隙
│                            └────┘    │
│                                    │
│▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓│  <- 地面
└────────────────────────────────────┘
```

---

## 12. 已知限制

1. 文字绘制为简化实现 (8x8 字符块)
2. 不支持声音效果
3. 不支持存档/读档
4. 不支持皮肤/自定义

---

## 13. 未来改进

- [ ] 添加声音效果
- [ ] 改进文字渲染
- [ ] 添加最高分记录
- [ ] 添加难度选择
- [ ] 添加皮肤系统
- [ ] 支持 Linux/macOS

---

*文档版本: 1.0.0 | 更新日期: 2026-04-06*
