# 2048 Game - Zen-C Windows Mini Games DIY

A classic 2048 puzzle game built with Zen-C language using the 003-framework.

## Game Features

- **4x4 Grid**: Classic 2048 gameplay on a 4x4 grid
- **Smooth Controls**: Arrow keys to move tiles in all directions
- **Score System**: Track your score as you combine tiles
- **Win Condition**: Reach 2048 to win!
- **Game Over Detection**: Game ends when no more moves are possible
- **Restart**: Press Enter or R to restart at any time

## Controls

| Key | Action |
|-----|--------|
| ← | Move tiles left |
| ↑ | Move tiles up |
| → | Move tiles right |
| ↓ | Move tiles down |
| R | Restart game |
| ESC | Exit game |

## Tile Values & Colors

| Value | Color |
|-------|-------|
| 2 | Light beige |
| 4 | Cream |
| 8 | Orange |
| 16 | Dark orange |
| 32 | Red-orange |
| 64 | Red |
| 128 | Gold |
| 256 | Dark gold |
| 512 | Darker gold |
| 1024 | Orange gold |
| 2048 | Bright gold (WIN!) |

## Building

### Prerequisites

- Zen-C compiler (zc)
- GCC compiler (for C backend)
- Windows OS (for Windows build)

### Build on Linux/macOS

```bash
cd src/009-2048
make
```

### Build on Windows

```batch
cd src\009-2048
build_windows.bat
```

Or use the Makefile with WSL:

```bash
make windows
```

## Project Structure

```
009-2048/
├── src/
│   ├── main_window.zc   # Main game window, inherits from Game class
│   ├── game2048.zc      # Game logic (board, movement, merging)
│   └── platform_api.zc  # Platform API (imported from framework)
├── docs/
│   └── design/          # Design documents
├── README.md
├── Makefile
└── build_windows.bat
```

## Architecture

### Game Class

The game inherits from the framework's `Game` class and implements:
- `onInit()` - Initialize game state and board
- `onUpdate(dt)` - Update game logic (input-driven)
- `onRender(canvas)` - Render game board and UI
- `onKeyDown(key)` - Handle arrow key input

### Game Logic (game2048.zc)

- `Board` - 4x4 grid of integers
- `GameData` - Contains board, score, win/lose states
- `move_left/right/up/down()` - Tile movement and merging
- `add_random_tile()` - Spawn new 2 or 4 tile
- `can_move()` - Check if any moves are possible
- `check_won()` - Check for 2048 tile

## License

Same as the parent project.

## Part of Windows Mini Games DIY

This game is part of the [windows-minigames-diy](https://github.com/xingmu/windows-minigames-diy) collection of classic games built with Zen-C.
