// Lucky numbers in a matrix
// EASY

#include <stdio.h>
#include <stdlib.h>

int maxInColumn(int** matrix, int matrixSize, int pos) {
  int maximum = 0;
  for (int i = 0; i < matrixSize; i ++) {
    maximum = fmax(maximum, matrix[i][pos]);
  }

  return maximum;
}

int* luckyNumbers (int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
  int* array = (int*)malloc(sizeof(int));

  for (int i = 0; i < matrixSize; i ++) {
    int minimumInd = 0;
    for (int j = 0; j < *matrixColSize; j ++) {
      if (matrix[i][minimumInd] > matrix[i][j]) {
        minimumInd = j;
      }
    }

    if (matrix[i][minimumInd] == maxInColumn(matrix, matrixSize, minimumInd)) {
      array[0] = matrix[i][minimumInd];
      *returnSize = 1;
      return array;
    }
  }


  *returnSize = 0;
  return array;
}
