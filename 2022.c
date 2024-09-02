// Convert 1D array into 2D array
// EASY

#include <stdio.h>
#include <stdlib.h>

int** construct2DArray(int* original, int originalSize, int m, int n, int* returnSize, int** returnColumnSizes) {
  if (originalSize != m * n) {
    *returnSize = 0;
    *returnColumnSizes = NULL;
    return NULL;
  }

  int pos = 0;
  int** matrix = (int**)malloc(m * sizeof(int*));
  for (int i = 0; i < m; i ++) {
    matrix[i] = (int*)malloc(n * sizeof(int));
    for (int j = 0; j < n; j ++) {
      matrix[i][j] = original[pos ++];
    }
  }

  *returnSize = m;
  *returnColumnSizes = (int*)malloc(m * sizeof(int));
  for (int i = 0; i < m; i ++) {
    (*returnColumnSizes)[i] = n;
  }

  return matrix;
}
