// Minimum number of flips to make binary grid palindromic I
// MEDIUM

#include <stdio.h>

int minFlips(int** grid, int gridSize, int* gridColSize) {
  int colCount = 0;
  int rowCount = 0;
  
  for (int i = 0; i < gridSize; i ++) {
    for (int j = 0; j < *gridColSize / 2; j ++) {
      if (grid[i][j] != grid[i][*gridColSize - j - 1]) {
        colCount ++;
      }
    }
  }
  
  for (int i = 0; i < *gridColSize; i ++) {
    for (int j = 0; j < gridSize / 2; j ++) {
      if (grid[j][i] != grid[gridSize - j - 1][i]) {
        rowCount ++;
      }
    }
  }
  
  return fmin(rowCount, colCount);
}
