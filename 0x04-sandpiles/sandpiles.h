#ifndef SANDPILES_H
#define SANDPILES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add_sand(int grid1[3][3], int grid2[3][3]);
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
void print_gridd(int grid[3][3]);
int check_stable(int grid1[3][3]);

#endif
