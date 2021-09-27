#include "slide_line.h"

/**
* slide_line - The goal of this task is to reproduce the 2048...
* ...game(NSFW !!) mechanics on a single horizontal line.
* @line: points to an array of integers containing...
* @size: elements that must be slide and merged to the direction
* ...represented by...
* @direction: direction to slide (SLIDE_LEFT & SLIDE_RIGHT)
* Return: 1 for success, and 0 otherwise
*/
int slide_line(int *line, size_t size, int direction)
{
	int i, temp = 0; /* temp is 1 behind i except if temp's value is 0 */

	if ((size <= 0) || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
		return (0);
	if (direction == SLIDE_LEFT)
	{
		for (i = 1; i < (int)size; i++)
		{
			if (line[i] && line[i] == line[temp])
			{
				line[temp++] += line[i], line[i] = 0;
			}
			else if (line[i] && line[i] != line[temp])
			{
				if (line[temp] != 0)
					temp++;
				else
					line[temp] += line[i], line[i] = 0;
			}
		}
	}
	else if (direction == SLIDE_RIGHT)
	{
		temp = size - 1;
		for (i = size - 2; i >= 0; i--)
		{
			if (line[i] && line[i] == line[temp])
			{
				line[temp--] += line[i], line[i] = 0;
			}
			else if (line[i] && line[i] != line[temp])
			{
				if (line[temp] != 0)
					temp--;
				else
					line[temp] += line[i], line[i] = 0;
			}
		}
	}
	return (1);
}
