#include "sort.h"

/**
* merge_sort - a function that sorts an array of integers in...
* ...ascending order using the Merge Sort algorithm
* @array: array to sort
* @size: size of the array
*/
void merge_sort(int *array, size_t size)
{
	size_t i, j, k;
	int *tmp;

	if (size < 2)
		return;

	tmp = malloc(sizeof(int) * size);
	if (tmp == NULL)
		return;

	for (i = 0; i < size; i++)
		tmp[i] = array[i];

	for (i = 0, j = size / 2, k = 0; k < size; k++)
	{
		if (j >= size)
			array[k] = tmp[i++];
		else if (i >= size / 2)
			array[k] = tmp[j++];
		else if (tmp[i] < tmp[j])
			array[k] = tmp[i++];
		else
			array[k] = tmp[j++];
	}
	free(tmp);
}
