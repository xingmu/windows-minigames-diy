# 2048 Game Design Document

## Overview

This document describes the design and implementation of the 2048 puzzle game built with Zen-C language using the 003-framework.

## Game Specification

### Core Mechanics

- **Grid**: 4x4 matrix of integer values
- **Initial State**: Two random tiles (value 2 or 4) placed on the grid
- **Movement**: Arrow keys move all tiles in a direction
- **Merging**: Adjacent tiles with the same value combine into one tile with doubled value
- **Spawning**: After each move, a new tile (2 or 4) appears in a random empty cell
- **Scoring**: Each merge adds the new tile's value to the score
- **Win Condition**: Creating a tile with value 2048
- **Lose Condition**: No empty cells AND no adjacent tiles can merge

### Tile Values

| Value | Color (RGB) | Description |
|-------|-------------|-------------|
| 0 | #CCC0B4 | Empty cell background |
| 2 | #EEE4DA | Light beige |
| 4 | #EDE0C8 | Cream |
| 8 | #F2B179 | Orange |
| 16 | #F59563 | Dark orange |
| 32 | #F67C5F | Red-orange |
| 64 | #F65E3B | Red |
| 128 | #EDCF72 | Gold |
| 256 | #EDCC61 | Dark gold |
| 512 | #EDC850 | Darker gold |
| 1024 | #EDC53F | Orange gold |
| 2048 | #EDC22E | Bright gold (WIN) |
| 4096+ | #3C3A32 | Dark (super tile) |

## Architecture

### Class Structure

```
Game2048 (extends Game)
├── game_data: GameData
│   ├── board: Board
│   │   └── cells: [16]i32
│   ├── score: i32
│   ├── won: bool
│   └── game_over: bool
├── onInit()
├── onUpdate(dt)
├── onRender(canvas)
├── onKeyDown(key)
└── ... (other callbacks)
```

### Module Dependencies

```
main_window.zc (入口)
├── platform_api.zc (框架)
├── game.zc (框架)
└── game2048.zc (游戏逻辑)
    └── std.math, std.time
```

### Key Functions

#### game2048.zc

| Function | Purpose |
|----------|---------|
| `init_game()` | Initialize board, spawn 2 tiles |
| `add_random_tile()` | Add new 2 or 4 tile randomly |
| `move_left/right/up/down()` | Move and merge tiles in direction |
| `can_move()` | Check if any move is possible |
| `check_won()` | Check for 2048 tile |
| `get_tile_value()` | Get value at grid index |

#### main_window.zc

| Function | Purpose |
|----------|---------|
| `Game2048.create()` | Constructor, call parent create |
| `onRender()` | Draw background, grid, tiles, UI |
| `onKeyDown()` | Handle arrow key input |
| `draw_title()` | Render "2048" title |
| `draw_score()` | Show current score |
| `draw_grid()` | Draw 4x4 cell backgrounds |
| `draw_tiles()` | Draw all tile values with colors |
| `draw_win_message()` | Show win overlay |
| `draw_gameover_message()` | Show game over overlay |

## Data Structures

### Board

```zen
struct Board {
    cells: [16]i32  // 4x4 grid, row-major
}
```

Cell index calculation: `index = y * 4 + x`

### GameData

```zen
struct GameData {
    board: Board,
    score: i32,
    won: bool,
    game_over: bool,
    moved: bool
}
```

## Game Flow

1. **Init**: Create window, call `init_game()`
2. **Input Loop**: Wait for arrow key
3. **Move**: Call `move_*()` based on key
4. **Spawn**: Call `add_random_tile()`
5. **Check**: Check win/lose conditions
6. **Render**: Call `onRender()` to update display
7. **Repeat**: Until ESC or game over

## Rendering Approach

Since Zen-C's framebuffer canvas uses a simple pixel buffer, text rendering is simplified:
- **Tiles**: Filled rectangles with solid colors
- **Numbers**: Simulated with rectangular blocks (placeholder for real font rendering)
- **UI**: Basic shapes and colors

This is intentional - the focus is on game logic rather than advanced graphics.

## Window Dimensions

- Width: 480 pixels
- Height: 640 pixels
- Grid area: 440 x 440 pixels (100x100 per cell + gaps)
- Title bar: Top 100 pixels
- Info area: Bottom portion

## Future Improvements

1. **Real text rendering**: Integrate font library for proper number display
2. **Animation**: Smooth tile sliding animation
3. **Sound effects**: Add move and merge sounds
4. **High score**: Persist best score
5. **Touch support**: Mobile-friendly controls
6. **Undo feature**: Allow reverting moves

## References

- Original 2048 game: https://play2048.co/
- Zen-C language: https://github.com/z-libs/Zen-C
- 003-framework: ../003-framework/
