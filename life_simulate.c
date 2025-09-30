#pragma warning(push, 0)
#include <stdint.h>

#define WIN32_LEAN_AND_MEAN
#define UNICODE
#include <windows.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#pragma(pop)

#pragma warning(disable :5045)

// int		is_malloced = 0;

typedef struct start_coord_s
{
	uint32_t x;
	uint32_t y;
} start_coord_t;

int	count_alive_neigb(start_coord_t cur_coord, int max_dim, char **grid)
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
			alive_neigb =+ (grid[((x + i) * max_dim + (y + j))] == '1');
		}
	}
	return (alive_neigb);
}

uint8_t *simulate_life(uint32_t grid_dim, start_coord_t *initial_points, uint32_t initial_point_count)
{

	// if (!is_malloced)
	// {
	// 	is_malloced = 1;
	// 	grid = malloc(256);
	// }
	// char **local_grid = (char **)grid;
	char			*grid;
	int				counter;
	start_coord_t	cpy_init;
	int	grid_rows = grid_dim;
	int	grid_cols = grid_dim;
	int				ngb;

	// int				iteration = 0;

	grid = malloc(grid_dim * sizeof(char *));
	if (!grid)
		OutputDebugStringA("malloc error in grid");
		
	grid = malloc(grid_dim * grid_dim);
	for (int x = 0; x < grid_dim; x++)
	{
		for (int y = 0; y < grid_dim; y++)
		{
			grid[x * ((grid_dim)) + y] = '\0';
		}
	}
	ngb = 0;
	counter = -1;
	while (++counter < initial_point_count)
	{
		cpy_init = initial_points[counter];

		grid[(cpy_init.x * grid_dim) + cpy_init.y] = '1';
	}
	for (int rows = 3; rows < 7; rows++)
	{
		for (int cols = 3; cols < 7; cols++)
		{
			cpy_init.x = rows;
			cpy_init.y = cols;
			ngb = count_alive_neigb(cpy_init, grid_dim, grid);
			if (grid[(cpy_init.x * grid_dim) + cpy_init.y] == '1')
			{
				if ((ngb >= 2 && ngb <= 3))
					continue;
				else
				{
					grid[(cpy_init.x * grid_dim) + cpy_init.y] = '\0';
					continue;
				}
			}
			else
			{
				if (ngb == 3)
					grid[(cpy_init.x * grid_dim) + cpy_init.y] = '1';
			}
		}
	}
	return (grid);
}

