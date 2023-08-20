#include "main.h"
/**
 * free_grid - free up 2 grid
 * @grid: Array of pointers.
 */
void free_grid(char **grid)
{
	int i = 0;

	while (grid[i])
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}
