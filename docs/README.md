# Rugby 游戏开发文档

## 概述

Rugby 是一款使用 Zen-C 语言开发的橄榄球达阵游戏，基于 003-framework 游戏框架。

## 游戏设计

### 核心玩法
- 玩家控制绿色球员在橄榄球场地上移动
- 目标是将球带入对方达阵区(TRY ZONE)得分
- 红色防守球员会追捕持球者
- 可以传球给队友来躲避防守

### 计分系统
- 达阵得分: 5分
- 比赛时间: 120秒(2分钟)

### 球员控制
- **玩家(绿色)**: 方向键移动，空格键传球
- **队友(青色)**: AI自动跑位到达阵区
- **防守(红色)**: AI追捕最近的持球者

## 技术架构

### 文件结构
```
src/
├── main_window.zc        # 程序入口
├── game.zc              # 游戏框架(Game类)
├── game_logic.zc        # RugbyGame类(游戏逻辑)
├── platform_api.zc      # 平台API定义
└── platform_api_windows.zc  # Windows实现
```

### 主要类

#### Game (game.zc)
- 游戏基础类
- 提供窗口管理、消息循环、帧率控制
- 子类需要实现: onInit, onUpdate, onRender, onKeyDown 等

#### RugbyGame (game_logic.zc)
- 继承自 Game
- 实现具体游戏逻辑
- 管理球员、球、防守球员的状态

### 游戏状态机

```
Ready -> Playing -> TryScored -> Playing -> GameOver
         ^                                |
         |________________________________|
```

### AI 系统

#### 队友AI
- 向达阵区方向跑动
- 保持分散的队形
- 接应传球

#### 防守AI  
- 追捕最近的持球者
- 优先追捕玩家
- 擒抱后夺球

## 渲染系统

### 画布接口 (Canvas)
- clear(color): 清屏
- fillRect/fillCircle: 绘制图形
- drawText: 绘制文字
- drawLine: 绘制线条

### 颜色格式
- 使用 ARGB 格式
- Color.Static 方法创建常用颜色
- Color.RGB(r,g,b) 创建RGB颜色

## 事件处理

### 键盘事件
- onKeyDown: 按下按键
- onKeyUp: 释放按键
- VirtualKey 枚举定义所有按键

### 鼠标事件
- onMouseDown: 鼠标按下
- onMouseUp: 鼠标释放

## 调试建议

1. 先运行空游戏窗口测试
2. 逐个添加游戏元素
3. 使用调试输出了解状态变化
4. 测试边界条件(碰撞、越界等)

## 扩展方向

- 添加更多游戏模式(挑战模式、练习模式)
- 增加道具系统
- 添加特殊技能
- 改进AI行为
- 添加音效和背景音乐
- 支持多人游戏
