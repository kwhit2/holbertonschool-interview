#include <stdio.h>
#include <stdlib.h>

#include "menger.h"

/**
* CarpetPrint - a helper function that prints a 2D Menger Sponge
* @carp: Carpet to print
* Return: void
*/
void CarpetPrint(Carpet carp)
{
	char obuf[730];
	int row;

	for (row = 0; row < carp->dim; row++)
	{
		strncpy(obuf, carp->rows[row], carp->dim);
		printf("%s\n", obuf);
	}
}

/**
 * main - Entry point
 *
 * @ac: Arguments counter
 * @av: Arguments vector
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int ac, char **av)
{
	int level;

	if (ac < 2)
	{
		fprintf(stderr, "Usage: %s level\n", av[0]);
		return (EXIT_FAILURE);
	}

	level = atoi(av[1]);
	menger(level);

	return (EXIT_SUCCESS);
}
