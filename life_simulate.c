#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "life_simulate.h"

int		is_malloced = 0;
uint8_t	*grid;

int	count_alive_neigb(start_coord_t cur_coord, int max_dim, uint8_t *grid)
{
	int	x = cur_coord.x;
	int	y = cur_coord.y;
	int	alive_neigb = 0;

	for (int i = -1; i < 2; i++)
	{
		for (int j = -1; j < 2; j++)
		{
			if (!(x + i >= 0 && x + i < max_dim))
				continue ;
			if (!(y + j >= 0 && y + j < max_dim))
				continue ;
			if (i == 0 && j == 0)
			{
				continue;
			}
			alive_neigb += (grid[((x + i) * max_dim + (y + j))] == 1);
		}
	}
	return (alive_neigb);
}

uint8_t *simulate_life(uint32_t grid_dim, start_coord_t *initial_points, uint32_t initial_point_count)
{
	uint32_t		counter;
	start_coord_t	cpy_init;

	if (!is_malloced)
	{
		grid = malloc(grid_dim * grid_dim);
		is_malloced = 1;
	}
	memset(grid, 0, grid_dim * grid_dim);
	
	counter = 0;
	while (counter < initial_point_count)
	{
		cpy_init = initial_points[counter];
		grid[(cpy_init.x * grid_dim) + cpy_init.y] = 1;
		counter++;
	}
	
	return (grid);
}

uint8_t *step_life(uint32_t grid_dim)
{
	start_coord_t	cpy_init;
	int				ngb;
	uint8_t			*new_grid;
	
	if (!is_malloced || !grid)
		return NULL;
	
	new_grid = malloc(grid_dim * grid_dim);
	memset(new_grid, 0, grid_dim * grid_dim);
	
	for (uint32_t cols = 0; cols < grid_dim; cols++)
	{
		for (uint32_t rows = 0; rows < grid_dim; rows++)
		{
			cpy_init.x = cols;
			cpy_init.y = rows;
			ngb = count_alive_neigb(cpy_init, grid_dim, grid);
			if (grid[(cols * grid_dim) + rows] == 1)
			{
				if (ngb >= 2 && ngb <= 3)
					new_grid[(cols * grid_dim) + rows] = 1;
			}
			else
			{
				if (ngb == 3)
					new_grid[(cols * grid_dim) + rows] = 1;
			}
		}
	}
	
	memcpy(grid, new_grid, grid_dim * grid_dim);
	free(new_grid);
	
	return (grid);
}

void cleanup_life(void)
{
	if (is_malloced && grid)
	{
		free(grid);
		grid = NULL;
		is_malloced = 0;
	}
}

