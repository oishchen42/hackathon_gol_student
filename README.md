# AnyDesk Hackathon 2025 - Conway's Game of Life

Welcome to the AnyDesk Hackathon 2025!

This repository contains a high-performance implementation of **Conway's Game of Life** written in C for Windows.

## 📖 About Conway's Game of Life

Conway's Game of Life is a cellular automaton devised by mathematician John Horton Conway in 1970. It's a zero-player game where the evolution of the grid is determined by its initial state, requiring no further input.

### Rules

The game consists of a grid of cells which can either be alive or dead. The state of each cell evolves according to these simple rules:

1. **Survival**: A live cell with 2 or 3 live neighbors survives to the next generation
2. **Death**: A live cell with fewer than 2 neighbors dies (underpopulation), and a live cell with more than 3 neighbors dies (overpopulation)
3. **Birth**: A dead cell with exactly 3 live neighbors becomes alive (reproduction)

These simple rules create surprisingly complex patterns and behaviors!

## 🏗️ Project Structure

```
hackathon_gol_student/
├── life_simulate.c      # Core simulation logic (YOUR CODE HERE)
├── life_main.obj        # Main program entry point (pre-compiled)
├── life_renderer.obj    # Rendering engine (pre-compiled)
├── build_debug.bat      # Debug build script
├── build_release.bat    # Release build script
└── README.md            # This file
```

### Implementation Details

The `life_simulate.c` file contains the `simulate_life()` function which:
- Takes a grid dimension and initial alive cell coordinates
- Computes one generation/iteration of the Game of Life
- Returns a pointer to the updated grid state

The `count_alive_neigb()` function counts the number of alive neighbors for any given cell, considering edge cases at grid boundaries.

## 🚀 Setup

### Prerequisites
- Windows operating system
- Microsoft Visual C++ Compiler (MSVC)
- Visual Studio Build Tools or Visual Studio

### Installation

1. Fork this repository and submit the link to your forked repo to the Google Form:
   ```
   https://forms.gle/5JXT4Bcdo8wLM6GZ6
   ```

2. Clone your forked repository:
   ```bash
   git clone <your-forked-repo-url> C:/Users/anydesk/hackathon_gol
   cd C:/Users/anydesk/hackathon_gol
   ```

## 🔨 Building the Project

Open Windows Terminal in the project directory and choose one of the following build options:

### Debug Build
```bash
build_debug.bat
```
Creates a debug build with symbols that you can step through in a debugger like [raddbg](https://github.com/EpicGames/raddebugger).

### Release Build (Recommended for Performance Testing)
```bash
build_release.bat
```
Creates an optimized release build with compiler optimizations enabled. **This is how the final evaluation will be performed.**

## ▶️ Running the Simulation

After building, run the compiled executable:
```bash
life_simulate.exe
```

## 🎯 Hackathon Challenge

Your goal is to **optimize the `simulate_life()` function** in `life_simulate.c` to make it as fast as possible while maintaining correctness.

### Tips for Optimization
- Consider algorithmic improvements
- Look for redundant computations
- Think about memory access patterns
- Utilize compiler optimizations
- Profile your code to find bottlenecks

## 📊 Performance Evaluation

The final evaluation will use:
- Release build with full compiler optimizations (`/O2`)
- Various grid sizes and initial configurations
- Timing measurements to compare implementations

## 🛠️ Development Tools

The repository includes VS Code configuration (`.vscode/tasks.json`) for easy building within the editor.

## 📝 Notes

- The grid uses a 1D array representation where `grid[x * grid_dim + y]` accesses cell (x, y)
- Cells are stored as `uint8_t` where 1 = alive, 0 = dead
- The grid is allocated once and reused across function calls for efficiency

## 🤝 Contributing

This is a hackathon project - feel free to experiment and optimize! Remember to test your changes with both debug and release builds.

## 📄 License

Part of the AnyDesk Hackathon 2025

---

Good luck with your optimization! 🚀
