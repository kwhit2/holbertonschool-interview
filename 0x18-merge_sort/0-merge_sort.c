#include "sort.h"

/**
* merge_sort - a function that sorts an array of integers in...
* ...ascending order using the Merge Sort algorithm
* @array: array to sort
* @size: size of the array
*/
void merge_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    merge_sort_rec(array, 0, size - 1);
}

void merge_sort_rec(int *array, size_t start, size_t end)
{
    size_t middle;

    if (start >= end)
        return;

    middle = (start + end) / 2;
    merge_sort_rec(array, start, middle);
    merge_sort_rec(array, middle + 1, end);
    merge(array, start, middle, end);
}

void merge(int *array, size_t start, size_t middle, size_t end)
{
    int *temp;
    size_t i, j, k;

    temp = malloc(sizeof(int) * (end - start + 1));
    if (temp == NULL)
        return;

    i = start;
    j = middle + 1;
    k = 0;

    while (i <= middle && j <= end)
    {
        if (array[i] < array[j])
            temp[k++] = array[i++];
        else
            temp[k++] = array[j++];
    }
}
