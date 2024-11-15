// Island perimeter
// EASY

#include <stdio.h>

int islandPerimeter(int** grid, int gridSize, int* gridColSize) {
  int res = 0;

  for (int i = 0; i < gridSize; i ++) {
    for (int j = 0; j < *gridColSize; j ++) {
      if (grid[i][j]) {
        if (i == 0 || !grid[i - 1][j]) {
          res ++;
        }

        if (j == 0 || !grid[i][j - 1]) {
          res ++;
        }

        if (i == gridSize - 1 || !grid[i + 1][j]) {
          res ++;
        }

        if (j == *gridColSize - 1 || !grid[i][j + 1]) {
          res ++;
        }
      }
    }
  }

  return res;
}
