// Is grapp bipartite?
// MEDIUM

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool dfs (int** grid, int gridSize, int* gridColSize, int* color, int source, int col) {
  color[source] = col;
  for (int i = 0; i < gridColSize[source]; i ++) {
    if (!color[grid[source][i]]) {
      if (!dfs(grid, gridSize, gridColSize, color, grid[source][i], -col)) {
        return false;
      }
    } else if (color[grid[source][i]] == color[source]) {
      return false;
    }
  }

  return true;
}

bool isBipartite(int** graph, int graphSize, int* graphColSize) {
  int* color = (int*)calloc(graphSize, sizeof(int));
  for (int i = 0; i < graphSize; i ++) {
    if (!color[i]) {
      if (!dfs(graph, graphSize, graphColSize, color, i, 1)) {
        return false;
      }
    }
  }

  return true;
}
