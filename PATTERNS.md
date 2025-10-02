# Game of Life Pattern Examples

This file contains various patterns you can use in the Game of Life simulation.
Copy and paste these into `main.c` to try different patterns.

## Glider (default)
A small pattern that moves diagonally across the grid.
```c
start_coord_t pattern[] = {
    {1, 2},
    {2, 3},
    {3, 1},
    {3, 2},
    {3, 3}
};
uint32_t pattern_count = 5;
```

## Blinker
A simple oscillator that alternates between horizontal and vertical.
```c
start_coord_t pattern[] = {
    {10, 9},
    {10, 10},
    {10, 11}
};
uint32_t pattern_count = 3;
```

## Toad
An oscillator with period 2.
```c
start_coord_t pattern[] = {
    {10, 10},
    {10, 11},
    {10, 12},
    {11, 9},
    {11, 10},
    {11, 11}
};
uint32_t pattern_count = 6;
```

## Beacon
Another period-2 oscillator.
```c
start_coord_t pattern[] = {
    {10, 10},
    {10, 11},
    {11, 10},
    {11, 11},
    {12, 12},
    {12, 13},
    {13, 12},
    {13, 13}
};
uint32_t pattern_count = 8;
```

## Lightweight Spaceship (LWSS)
A spaceship that moves horizontally.
```c
start_coord_t pattern[] = {
    {5, 5},
    {5, 6},
    {5, 7},
    {5, 8},
    {6, 4},
    {6, 8},
    {7, 8},
    {8, 4},
    {8, 7}
};
uint32_t pattern_count = 9;
```

## R-pentomino
A methuselah pattern that evolves for 1103 generations before stabilizing.
```c
start_coord_t pattern[] = {
    {10, 11},
    {10, 12},
    {11, 10},
    {11, 11},
    {12, 11}
};
uint32_t pattern_count = 5;
```

## Gosper Glider Gun
A pattern that produces gliders indefinitely (requires larger grid ~40x40).
```c
start_coord_t pattern[] = {
    // Left square
    {5, 5},
    {5, 6},
    {6, 5},
    {6, 6},
    // Left part
    {5, 15},
    {6, 15},
    {7, 15},
    {4, 16},
    {8, 16},
    {3, 17},
    {9, 17},
    {3, 18},
    {9, 18},
    {6, 19},
    {4, 20},
    {8, 20},
    {5, 21},
    {6, 21},
    {7, 21},
    {6, 22},
    // Right part
    {3, 25},
    {4, 25},
    {5, 25},
    {3, 26},
    {4, 26},
    {5, 26},
    {2, 27},
    {6, 27},
    {1, 29},
    {2, 29},
    {6, 29},
    {7, 29},
    // Right square
    {3, 39},
    {4, 39},
    {3, 40},
    {4, 40}
};
uint32_t pattern_count = 36;
```

## How to Use

1. Open `main.c`
2. Find the section where the initial pattern is defined
3. Replace the existing pattern array with one from above
4. Update `pattern_count` to match
5. Rebuild: `make clean && make`
6. Run: `./game_of_life [grid_size] [iterations] [delay_ms]`

For larger patterns like the Gosper Glider Gun, use a bigger grid:
```bash
./game_of_life 50 500 50
```
