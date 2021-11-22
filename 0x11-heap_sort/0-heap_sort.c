#include "sort.h"

/**
* heap_sort - a function that sorts an array of integers in ascending
* order using the (sift down) Heap sort algorithm
* @array: integers
* @size: size of the array
* Return: void
*/
void heap_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;
	helper_heap_sort(array, size, array, size);
}

/**
* helper_heap_sort - function that helps & prints
* @array: ints
* @size: size of the array
* @arrcpy: copy of entire array for printing
* @cpysize: copy of size for printing
* Return: void
*/
void helper_heap_sort(int *array, size_t size, int *arrcpy, size_t cpysize)
{
	int i = 0, temp = 0;

	for (i = (size / 2) - 1; i >= 0; i--)
	{
		sift_down(array, size, i, arrcpy, cpysize);
	}

	for (i = (size - 1); i > 0; i--)
	{
		temp = array[i];
		array[i] = array[0];
		array[0] = temp;
		arrcpy[i] = array[i];
		arrcpy[0] = array[0];
		print_array(array, size);
		sift_down(array, i, 0, arrcpy, cpysize);
	}
}

/**
* sift_down - function that sifts down
* @arr: ints
* @i: index
* @size: size of array
* @arrcpy: copy of entire array for printing
* @cpysize: copy of size of array for printing
* Return: void
*/
void sift_down(int *arr, size_t size, int i, int *arrcpy, size_t cpysize)
{
	int left, right, chonky;
	int temp = 0;

	left = 2 * i + 1;
	right = 2 * i + 2;
	chonky = i;

	if (left < (int)size && arr[left] > arr[chonky])
		chonky = left;

	if (right < (int)size && arr[right] > arr[chonky])
		chonky = right;

	if (chonky != i)
	{
		temp = arr[i];
		arr[i] = arr[chonky];
		arr[chonky] = temp;
		arrcpy[i] = arr[i];
		arrcpy[chonky] = arr[chonky];
		print_array(arr, size);
		sift_down(arr, size, chonky, arrcpy, cpysize);
	}
}
