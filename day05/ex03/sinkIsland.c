#include "header.h"
#include <stdlib.h>

void recurse(int **map, int row, int col)
{
    if (map[row][col] != 1)
        return ;
    if (map[row][col] == 1)
        map[row][col] = 0;
    if (row >= 1)
        recurse(map, row - 1, col);
    if (col >= 1)
        recurse(map, row, col - 1);
    if (map[row][col + 1] != -1)
        recurse(map, row, col + 1);
    if (map[row + 1] != NULL)
        recurse(map, row + 1, col);
}

void sinkIsland(int **map, int row, int col)
{
    recurse(map, row, col);
}