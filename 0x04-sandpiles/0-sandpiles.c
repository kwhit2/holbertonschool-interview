#include "sandpiles.h"

/**
* sandpiles_sum - Function that computes the sum of two sandpiles
* @grid1: sandpile1
* @grid2: sandpile2
* Return: void
*/
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid1[i][j] + grid2[i][j];
		}
	}
}

/**
* topple - Function to topple a sandpile
* @grid1: sandpile
* Return: void
*/
void topple(int grid1[3][3])
{
	int i, j, num;
	int nextgrid[3][3];

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			num = grid1[i][j];
			if (num < 4)
			{
				nextgrid[i][j] = grid1[i][j];
				print_gridd(grid1);
			}

			if (num >= 4)
			{
				nextgrid[i][j] = grid1[i][j];
				nextgrid[i + 1][j]++;
				nextgrid[i - 1][j]++;
				nextgrid[i][j + 1]++;
				nextgrid[i][j - 1]++;
				print_gridd(grid1);
			}
		}
	}
	grid1 = nextgrid;
}

/**
 * print_gridd - Print 3x3 grid
 * @grid: 3x3 grid
 * Return: void
 */
void print_gridd(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
