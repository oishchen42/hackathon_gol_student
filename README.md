# AnyDesk Hackathon 2025

Welcome to the AnyDesk Hackathon 2025!

## Overview

This is a cross-platform implementation of Conway's Game of Life. The project has been refactored to work on Linux, macOS, and Windows (with appropriate C compiler).

## Project Structure

- `life_simulate.c` - Core Game of Life simulation logic (cross-platform)
- `life_simulate.h` - Header file with function declarations and types
- `main.c` - Main program with console-based rendering
- `Makefile` - Build configuration for Unix-like systems

## Building the Project

### On Linux/macOS/Unix:

```bash
make
```

This will create an executable called `game_of_life`.

### On Windows (with MinGW or WSL):

```bash
make
```

Or compile manually:
```bash
gcc -Wall -Wextra -std=gnu99 -O2 -c main.c
gcc -Wall -Wextra -std=gnu99 -O2 -c life_simulate.c
gcc -o game_of_life main.o life_simulate.o
```

## Running the Simulation

Run with default settings (20x20 grid, 100 iterations, 100ms delay):
```bash
./game_of_life
```

Customize the simulation:
```bash
./game_of_life [grid_size] [iterations] [delay_ms]
```

Examples:
```bash
./game_of_life 30 200 50    # 30x30 grid, 200 iterations, 50ms delay
./game_of_life 15 100 100   # 15x15 grid, 100 iterations, 100ms delay
```

## Features

- **Cross-platform**: Works on Linux, macOS, and Windows
- **Console-based rendering**: Uses simple ASCII/Unicode characters to display the grid
- **Configurable**: Adjust grid size, number of iterations, and animation speed
- **Classic patterns included**: Glider pattern included as default (easily swappable with other patterns)

## Customizing Initial Patterns

Edit `main.c` and modify the initial pattern arrays. Examples included in the code:
- Glider (default)
- Blinker (commented out)

You can add your own patterns by defining coordinates in the `start_coord_t` array.

## Implementation Details

The simulation uses a double-buffering approach to correctly apply Game of Life rules:
1. `simulate_life()` - Initializes the grid with an initial pattern
2. `step_life()` - Evolves the grid by one generation
3. `cleanup_life()` - Frees allocated memory

The rendering is done via a simple console output with borders and Unicode block characters (█) for alive cells.

## Cleaning Up

To remove compiled files:
```bash
make clean
```
