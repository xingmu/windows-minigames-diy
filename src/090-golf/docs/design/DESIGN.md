# Golf Game Design Document

## 1. Game Overview

**Name**: Zen-C Mini Golf  
**Type**: 2D Top-down Golf Simulation  
**Core**: Single-player golf game with 18 holes, physics-based ball movement

## 2. Visual Specification

### Canvas
- **Resolution**: 900x550 pixels
- **Render**: Direct framebuffer access (double-buffered)

### Color Palette
- **Background**: `#0F3C0F` (Deep Forest Green)
- **Fairway**: `#238C23` (Bright Green)
- **Rough**: `#145014` (Dark Green)  
- **Sand**: `#E6D28C` (Sandy Beige)
- **Water**: `#1E64C8` (Deep Blue)
- **Trees**: `#146414` (Tree Green) / `#196419` (Highlight)
- **Ball**: `#FFFFFF` (White)
- **UI**: `#146414` (Dark Green panels)
- **Text**: `#FFFF00` (Yellow), `#FFFFFF` (White)

### UI Layout
- **Top bar (40px)**: Hole info, strokes, total strokes, wind
- **Bottom bar (35px)**: Status text, controls hint
- **Minimap (right side)**: 100x20px course overview with ball position

## 3. Course Design

### Course Dimensions
- **Total length**: 9000 pixels
- **Width**: 500 pixels (with margins)
- **Playable area**: 60-460 Y coordinates

### Terrain Zones
| Type | Friction | Visual |
|------|----------|--------|
| Grass | 3 | Default green |
| Fairway | 2 | Brighter green strip |
| Rough | 5 | Darker green |
| Sand | 8 | Beige |
| Water | 2 | Blue (ball reset) |
| Hole | 1 | Green with flag |

### Holes (18 total)
Sequential par-3, par-4, par-5 holes with varying:
- Tee positions
- Hole positions
- Terrain obstacles
- Hazard placement

### Obstacles
- **Trees**: Brown trunk + green circular canopy
  - Collision: Ball bounces off with 0.3 velocity retention
- **Pockets**: Various water hazards

## 4. Physics Specification

### Ball Physics
- **Radius**: 6 pixels
- **Velocity**: Vector (vx, vy) in pixels/frame
- **Initial speed**: `power * 0.8` where power is 1-25

### Friction Model
```
velocity *= (1.0 - friction * 0.02)
```
Applied per-frame until `|velocity| < 0.1`

### Wind
- Range: -3 to +3
- Effect: `vx += wind * 0.01` per frame
- Displayed in UI as "左/右/无"

### Collision Response
- **Walls**: Velocity reflected with 0.5 retention
- **Trees**: Velocity reflected with 0.3 retention
- **Water**: Ball resets to tee, +1 stroke penalty

### Hole Detection
- Distance to hole center < 10 pixels
- Ball speed < 5.0
- Result: Ball enters hole

## 5. Interaction Specification

### Mouse Controls
| Action | Effect |
|--------|--------|
| Click + Drag | Aim direction (opposite of drag), power = drag distance / 4 |
| Release | Shoot ball with accumulated power |
| Click (after hole) | Next hole |
| Click (game over) | Restart |

### Visual Feedback
- **Aiming line**: Yellow dashed line from ball
- **Power bar**: 100x10px bar, green→yellow→red gradient
- **Club indicator**: Brown line from ball opposite to aim direction

### Game States
1. `Ready` - Waiting for player input
2. `Dragging` - Player is aiming
3. `Moving` - Ball in motion
4. `HoleComplete` - Ball entered hole
5. `GameOver` - All 18 holes complete

## 6. Camera System

- **Target**: Ball X position centered in viewport
- **Smoothing**: `cameraX += (targetX - cameraX) / 5`
- **Bounds**: Clamped to `[0, courseWidth - VIEW_WIDTH]`

## 7. Scoring

- **Stroke count**: Per hole and cumulative
- **Par system**: Each hole has target strokes
- **Display**: Current hole strokes vs par

## 8. Technical Implementation

### File Structure
```
src/
  main_window.zc     - Entry point, rendering, event loop
  game_logic.zc      - Physics, state, course data
  platform_api.zc    - Cross-platform API definitions
  platform_api_windows.zc - Windows implementation
  game.zc           - Framework base
```

### Build
```bash
zc -O2 -o build/golf.exe src/*.zc
```

### Frame Loop
```
1. Poll events (mouse, keyboard)
2. Update ball physics if moving
3. Update camera
4. Render all layers
5. Present framebuffer
6. Frame rate limit (60 FPS)
```

## 9. Acceptance Criteria

- [ ] Game launches without errors
- [ ] 18 distinct holes with correct par values
- [ ] Ball responds to click-drag-release input
- [ ] Ball rolls with friction deceleration
- [ ] Ball bounces off boundaries and obstacles
- [ ] Ball enters hole when close and slow enough
- [ ] Water hazard resets ball to tee
- [ ] Wind affects ball trajectory visibly
- [ ] Camera smoothly follows ball
- [ ] Minimap shows ball position on course
- [ ] Score tracks strokes per hole and total
- [ ] Game progresses through all 18 holes
