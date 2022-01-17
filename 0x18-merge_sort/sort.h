#ifndef _SORT_H_
#define _SORT_H_

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void print_array(const int *array, size_t size);
void merge_sort(int *array, size_t size);
void merge_sort_rec(int *array, size_t start, size_t end);
void merge(int *array, int *temp, size_t start, size_t mid, size_t end);

#endif
