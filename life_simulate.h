#ifndef LIFE_SIMULATE_H
#define LIFE_SIMULATE_H

#include <stdint.h>

typedef struct start_coord_s
{
	uint32_t x;
	uint32_t y;
} start_coord_t;

int count_alive_neigb(start_coord_t cur_coord, int max_dim, uint8_t *grid);
uint8_t *simulate_life(uint32_t grid_dim, start_coord_t *initial_points, uint32_t initial_point_count);
uint8_t *step_life(uint32_t grid_dim);
void cleanup_life(void);

#endif
