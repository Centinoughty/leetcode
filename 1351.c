// Count negative numbers in a sorted matrix
// EASY

#include <stdio.h>

int countNegatives(int** grid, int gridSize, int* gridColSize) {
  int count = 0;

  for (int i = 0; i < gridSize; i ++) {
    int j = *gridColSize - 1;
    while (j >= 0 && grid[i][j] < 0) {
      j --;
    }

      count += *gridColSize - j - 1;
  }

  return count;
}