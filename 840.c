// Magic squares in grid
// MEDIUM

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isValid (int** grid, int row, int col) {
  int* nums = (int*)calloc(10, sizeof(int));
  for (int i = row; i < row + 3; i ++) {
    for (int j = col; j < col + 3; j ++) {
      if (grid[i][j] > 9) {
        return false;
      } else if (nums[grid[i][j]] == 0) {
        nums[grid[i][j]] = 1;
      } else {
        return false;
      }
    }
  }

  return true;
}

bool isMagic (int** grid, int row, int col) {
  for (int i = row; i < row + 3; i ++) {
    if (grid[i][col] + grid[i][col + 1] + grid[i][col + 2] != 15) {
      return false;
    }
  }

  for (int j = col; j < col + 3; j ++) {
    if (grid[row][j] + grid[row + 1][j] + grid[row + 2][j] != 15) {
      return false;
    }
  }

  if (grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2] != 15) {
    return false;
  }

  if (grid[row + 2][col] + grid[row + 1][col + 1] + grid[row][col + 2] != 15) {
    return false;
  }

  return true;
}

int numMagicSquaresInside(int** grid, int gridSize, int* gridColSize) {
  int res = 0;

  if (gridSize < 3 || *gridColSize < 3) {
    return false;
  } else {
    for (int i = 0; i < gridSize - 2; i ++) {
      for (int j = 0; j < *gridColSize - 2; j ++) {
        if (isValid(grid, i, j) && isMagic(grid, i, j)) {
          res ++;
        }
      }
    }
  }

  return res;
}
