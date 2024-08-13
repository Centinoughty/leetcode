// Find valid matrix given row and column sums
// MEDIUM

#include <stdio.h>
#include <stdlib.h>

int** restoreMatrix(int* rowSum, int rowSumSize, int* colSum, int colSumSize, int* returnSize, int** returnColumnSizes) {
  int** array = (int**)malloc(rowSumSize * sizeof(int*));

  for (int i = 0; i < rowSumSize; i ++) {
    array[i] = (int*)malloc(colSumSize * sizeof(int));
    for (int j = 0; j < colSumSize; j ++) {
      array[i][j] = fmin(rowSum[i], colSum[j]);
      rowSum[i] -= array[i][j];
      colSum[j] -= array[i][j];
    }
  }

  *returnSize = rowSumSize;
  *returnColumnSizes = malloc(rowSumSize * sizeof(int));
  for (int i = 0; i < rowSumSize; i ++) {
    (*returnColumnSizes)[i] = colSumSize;
  }

  return array;
}
