# 华容道 Klotski Game - Zen-C Windows Mini Games DIY

Classic Chinese sliding block puzzle game (Klotski/HuarongDao) built with Zen-C language using the 003-framework.

## 🎮 Game Overview

华容道 (Klotski) is a classic sliding block puzzle originating from China. The goal is to move the largest block (representing Cao Cao, the warlord) to the exit at the bottom of the board.

## 🎯 Game Features

- **Classic Klotski Layout**: Traditional 4x5 grid with 10 blocks
- **Mouse Drag Controls**: Intuitive drag-and-drop piece movement
- **Move Counter**: Track your progress with move statistics
- **Win Detection**: Automatic victory check when Cao Cao reaches the exit
- **Restart Support**: Press R to restart at any time

## 🕹️ Controls

| Input | Action |
|-------|--------|
| **Mouse Drag** | Click and drag blocks to move them |
| **R** | Restart game |
| **ESC** | Exit game |

## 🎨 Block Types

| Block | Size | Description |
|-------|------|-------------|
| 🔴 Cao Cao | 2x2 | The red 2x2 block - guide to exit |
| 🔵 Generals | 1x2 or 2x1 | Vertical/horizontal generals |
| 🟡 Soldiers | 1x1 | Small soldier blocks |

## 📐 Game Rules

1. Blocks can only move horizontally or vertically
2. Blocks cannot pass through other blocks
3. The goal is to move Cao Cao to the exit at the bottom (green area)
4. Try to solve the puzzle in the minimum number of moves!

## 🏗️ Project Structure

```
022-huarongdao/
├── src/
│   ├── platform_api.zc           # Platform API definitions
│   ├── platform_api_windows.zc  # Windows implementation
│   ├── game.zc                  # Game framework core
│   ├── game_huarongdao.zc       # Klotski game logic
│   └── main_window.zc           # Main window & rendering
├── docs/
│   └── design/
│       └── DESIGN.md            # Game design document
├── build/                       # Build output
├── Makefile                     # Linux/macOS build
├── build_windows.bat           # Windows build
└── README.md                    # This file
```

## 🔧 Building

### Linux/macOS

```bash
make
```

### Windows

```batch
build_windows.bat
```

Or use Make:

```batch
make
```

## 📝 Game Implementation Details

### Board Layout

The game uses a 4-row × 5-column grid:

```
  0   1   2   3   4
┌───┬───┬───┬───┬───┐ 0
│ G │   G   │ G │ G │ 1
├───┼───┼───┼───┼───┤ 2
│ G │ G G │ G │ G │ 3
├───┴───┼───┴───┼───┤ 4
│   EXIT        │   │ 
└───────────────┴───┘ 
```

Legend: G = General blocks, G G = Horizontal blocks

### Win Condition

The game is won when Cao Cao (the 2x2 red block) reaches the exit position at row 2, column 2 (marked in green).

## 📜 History

华容道 (Klotski) has a long history in Chinese puzzle games. The puzzle is themed around the famous Three Kingdoms general Cao Cao's escape from Lu. The classic version uses 10 pieces of various sizes on a 4×5 board.

## 🤖 Technical Details

- **Language**: Zen-C
- **Framework**: 003-framework v1.0.0
- **Rendering**: Frame buffer direct pixel access
- **Window Size**: 440×420 pixels
- **Target FPS**: 60

---

**由 ZenC开发者 AI 助手自主管理** 🤖  
*游戏版本: 1.0.0 | 最后更新: 2026-04-06*
