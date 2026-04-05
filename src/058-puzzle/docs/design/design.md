# Slide Puzzle Design Document

## Overview

This document describes the design and implementation of the 8-puzzle (3x3 sliding tile puzzle) game built with Zen-C.

## Game Rules

1. The puzzle consists of a 3x3 grid with 8 numbered tiles and one empty space
2. Players slide tiles into the empty space to rearrange the puzzle
3. The goal is to arrange tiles 1-8 in order with the empty space at the bottom-right
4. Only tiles adjacent to the empty space can be moved

## Architecture

### Main Components

```
main_window.zc  - Game window and rendering (inherits from Game class)
game_logic.zc   - Puzzle logic and state management
platform_api.zc - Platform API wrapper (from framework)
```

### Game State

```zen-c
struct GameData {
    board: Board,      // 3x3 grid of tile values (0 = empty)
    moves: i32,        // Number of moves made
    solved: bool,      // Whether puzzle is solved
    started: bool,     // Whether game has started
    start_time: i64,   // Start timestamp
    end_time: i64      // Completion timestamp
}
```

### Key Functions

| Function | Description |
|----------|-------------|
| `shuffle_game()` | Generate a solvable random puzzle |
| `try_move(x, y)` | Move tile at (x,y) if adjacent to empty |
| `check_solved()` | Check if puzzle is in winning state |
| `handle_input()` | Process keyboard input |

## Input Handling

### Keyboard Controls

- Arrow keys move tiles
- WASD keys as alternative
- R key restarts with new puzzle
- ESC exits game

### Mouse Controls

- Click on a tile adjacent to empty space to move it

## Rendering

### Visual Elements

1. Title Bar: "SLIDE PUZZLE" rendered with colored blocks
2. Stats Display: Move counter and elapsed time
3. Puzzle Grid: 3x3 grid with numbered tiles
4. Tiles: Colored blocks with numbers 1-8
5. Win Overlay: Congratulations message when solved

## Win Detection

The puzzle is solved when tiles are in order: 1,2,3,4,5,6,7,8,(empty)

## Shuffle Algorithm

To ensure solvability, the puzzle is shuffled by making random valid moves from the solved state.
