// Number of islands
// MEDIUM

#include <stdio.h>

void dfs(char** grid, int gridSize, int* gridColSize, int i, int j) {
  if (i < 0 || i == gridSize || j < 0 || j == *gridColSize) {
    return;
  }

  if (grid[i][j] != '1') {
    return;
  }

  grid[i][j] = '2';
  dfs(grid, gridSize, gridColSize, i, j - 1);
  dfs(grid, gridSize, gridColSize, i - 1, j);
  dfs(grid, gridSize, gridColSize, i + 1, j);
  dfs(grid, gridSize, gridColSize, i, j + 1);
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
  int res = 0;

  for (int i = 0; i < gridSize; i++) {
    for (int j = 0; j < *gridColSize; j++) {
      if (grid[i][j] == '1') {
        dfs(grid, gridSize, gridColSize, i, j);
        res++;
      }
    }
  }

  return res;
}
