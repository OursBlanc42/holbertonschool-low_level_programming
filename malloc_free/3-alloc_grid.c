#include <stdlib.h>
#include "main.h"

/**
 * alloc_grid - returns a pointer to a 2 dimensional array of integers.
 * Description : returns a pointer to a 2 dimensional array of integers.
 * @width: width of the array
 * @height: height of the array
 * Return:	NULL on failure
 *			NULL if widht or height is 0 or negative
 *			else Return pointer 2 dimensional array of integers.
 */

int **alloc_grid(int width, int height)
{
	/* declaration and initialization */
	int i;
	int j;
	int **grid;

	/* check if width or height is 0 or negative */
	if ((width <= 0) || (height <= 0))
		return (NULL);

	/* Set up the grid by allocating memory for a 2D array */
	grid = malloc(height * sizeof(int *));

	/* check if memory allocation succeed */
	if (grid == NULL)
		return (NULL);

	/* Loop over each row to allocate memory for the columns */

	for (i = 0; i < height; i++)
	{
		grid[i] = malloc(width * sizeof(int));
		/* check if memory allocation succeed */
		if (grid[i] == NULL)
		{
			/* If allocation fails, free all allocated rows */
			for (j = 0; j < i; j++)
			{
				free(grid[j]);
			}
			return (NULL);
		}
	}

	/* Loop through grid and write "0" in each cells */
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			grid[i][j] = 0;
		}
	}

	return (grid);

}
