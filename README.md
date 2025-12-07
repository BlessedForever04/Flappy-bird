# 🐦 Flappy Bird

A classic terminal-based implementation of the popular Flappy Bird game in C.

## Overview

Navigate your bird through an endless stream of obstacles by timing your jumps perfectly. Simple controls, challenging gameplay, and addictive score-chasing await you!

## Features

- **Simple Controls**: Press SPACE to make your bird fly upward
- **Dynamic Obstacles**: Randomly generated pipe gaps to keep gameplay fresh
- **Score Tracking**: Your score increases with each obstacle you successfully pass
- **Smooth Animation**: 130ms frame rate for fluid gameplay
- **Game Over Detection**: Collide with pipes or boundaries to end your run

## Game Mechanics

- Your bird starts at height 10 on the screen
- Gravity pulls the bird down every frame if you don't flap
- Pressing SPACE lifts the bird up by 1 unit
- Obstacles appear on the right side and scroll left
- The game ends if you hit a pipe or go out of bounds
- Your final score is displayed when the game ends

## Building & Running

### Requirements
- GCC or MSVC compiler (C99 or later)
- Windows OS (uses Windows API for `Sleep()`)

### Compile
```bash
gcc -o flappy_bird main.c
```

### Run
```bash
./flappy_bird
```

## Technical Details

- **Language**: C
- **Platform**: Windows (uses `windows.h` for timing)
- **Map Dimensions**: 20 height × 150 length terminal grid
- **Bird Start Position**: Height 10, Column 40

## Game Loop

The game consists of:
1. Obstacle generation with random gap placement
2. Rendering the map with your bird position
3. Input handling (SPACE detection)
4. State updates (gravity, scrolling)
5. Collision detection
6. Repeat or end game


## Tips & Tricks

- **Timing is Everything**: Master the rhythm of flapping to sail through tight gaps
- **Track Your Best**: Keep playing to beat your high score
- **Stay Calm**: The faster you react, the better your flow

## Future Enhancements

- High score persistence
- Difficulty levels
- Sound effects
- Better graphics with ANSI colors
- Cross-platform support (Linux/macOS)

---

Enjoy the game and happy flapping!