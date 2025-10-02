#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include "life_simulate.h"

// Simple console rendering function
void render_grid(uint8_t *grid, uint32_t grid_dim)
{
	// Clear screen (ANSI escape code)
	printf("\033[2J\033[H");
	
	// Print top border
	printf("+");
	for (uint32_t i = 0; i < grid_dim; i++)
		printf("-");
	printf("+\n");
	
	// Print grid
	for (uint32_t row = 0; row < grid_dim; row++)
	{
		printf("|");
		for (uint32_t col = 0; col < grid_dim; col++)
		{
			if (grid[row * grid_dim + col] == 1)
				printf("█");  // Alive cell
			else
				printf(" ");  // Dead cell
		}
		printf("|\n");
	}
	
	// Print bottom border
	printf("+");
	for (uint32_t i = 0; i < grid_dim; i++)
		printf("-");
	printf("+\n");
}

int main(int argc, char **argv)
{
	uint32_t grid_dim = 20;
	uint32_t iterations = 100;
	uint32_t delay_ms = 100000; // 100ms = 100000 microseconds
	
	// Parse command line arguments
	if (argc > 1)
		grid_dim = atoi(argv[1]);
	if (argc > 2)
		iterations = atoi(argv[2]);
	if (argc > 3)
		delay_ms = atoi(argv[3]) * 1000;
	
	// Define initial pattern (Glider)
	start_coord_t glider[] = {
		{1, 2},
		{2, 3},
		{3, 1},
		{3, 2},
		{3, 3}
	};
	uint32_t glider_count = 5;
	
	// Alternative patterns for demonstration
	// Blinker pattern (comment out glider and uncomment this)
	// start_coord_t glider[] = {
	// 	{10, 9},
	// 	{10, 10},
	// 	{10, 11}
	// };
	// uint32_t glider_count = 3;
	
	// Print usage information
	printf("Game of Life Simulator\n");
	printf("Usage: %s [grid_size] [iterations] [delay_ms]\n", argv[0]);
	printf("Running with: grid_size=%u, iterations=%u, delay=%ums\n\n", 
	       grid_dim, iterations, delay_ms / 1000);
	printf("Press Ctrl+C to stop\n\n");
	sleep(2);
	
	// Set initial pattern
	uint8_t *grid = simulate_life(grid_dim, glider, glider_count);
	
	// Main simulation loop
	for (uint32_t i = 0; i < iterations; i++)
	{
		// Render the grid
		render_grid(grid, grid_dim);
		printf("Generation: %u\n", i + 1);
		
		// Delay before next iteration
		usleep(delay_ms);
		
		// Evolve to next generation
		grid = step_life(grid_dim);
	}
	
	// Cleanup
	cleanup_life();
	
	printf("\nSimulation complete!\n");
	
	return 0;
}
