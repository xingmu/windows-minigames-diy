# Archery Game - 设计文档

## 概述

Archery 是一款 Zen-C 语言开发的射箭游戏，玩家通过鼠标瞄准和蓄力射击来命中靶心。

## 游戏设计

### 核心玩法

1. **瞄准机制**
   - 弓位于屏幕底部中央
   - 弓的方向跟随鼠标位置
   - 准星显示在鼠标位置

2. **蓄力射击**
   - 按住鼠标左键开始蓄力
   - 力量条从 MIN_POWER 增长到 MAX_POWER
   - 松开鼠标发射箭矢
   - 箭矢初速度 = 蓄力值

3. **物理模拟**
   - 箭矢受重力影响（向下的加速度）
   - 箭矢受风力影响（水平加速度）
   - 箭矢角度随速度方向变化

### 计分系统

| 命中区域 | 颜色 | 基础分 | 连击加成 |
|----------|------|--------|----------|
| Bullseye | 金色 | 50分 | +5×连击数 |
| Inner Ring | 蓝色 | 30分 | +5×连击数 |
| Outer Ring | 白色 | 10分 | 无 |

### 游戏流程

1. **Ready 状态** - 显示开始画面
2. **Playing 状态** - 玩家射箭
3. **Reloading 状态** - 回合切换
4. **GameOver 状态** - 显示最终得分

## 技术实现

### 框架使用

- 基于 003-framework 构建
- 使用 framebuffer 直接像素绘制
- 事件驱动架构

### 数据结构

```zen-c
struct Arrow {
    x, y: float          // 位置
    vx, vy: float        // 速度
    angle: float         // 角度
    active: bool         // 是否激活
    trail: [20]Vec2      // 轨迹点
}

struct Target {
    x, y: i32            // 位置
    alive: bool          // 是否存活
    ring: i32            // 命中环数
}

struct Bow {
    x, y: i32            // 位置
    angle: float         // 瞄准角度
    power: float         // 当前力量
    drawing: bool        // 是否在蓄力
}
```

### 关键算法

1. **抛物线运动**
   ```
   vy = vy + GRAVITY
   vx = vx + WIND
   x = x + vx
   y = y + vy
   ```

2. **角度计算**
   ```
   angle = atan2(mouseY - bowY, mouseX - bowX)
   ```

3. **碰撞检测**
   ```
   dist = sqrt((arrowX - targetX)² + (arrowY - targetY)²)
   if dist < OUTER_RADIUS: 命中
   ```

## 美术资源

- 使用程序生成的 2D 图形
- 天空渐变背景
- 圆形靶心（3环）
- 弓和箭矢的程序化绘制

## 后续扩展

- [ ] 添加更多靶子类型
- [ ] 添加关卡系统
- [ ] 添加特殊箭矢类型
- [ ] 添加音效和音乐
- [ ] 添加粒子效果
