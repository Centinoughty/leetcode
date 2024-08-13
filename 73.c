// Set matrix zeroes
// MEDIUM

#include <stdio.h>
#include <stdbool.h>

void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
  bool fillFirstRow = false;
  bool fillFirstCol = false;

  for (int i = 0; i < *matrixColSize; i ++) {
    if (matrix[0][i] == 0) {
      fillFirstRow = true;
      break;
    }
  }

  for (int i = 0; i < matrixSize; i ++) {
    if (matrix[i][0] == 0) {
      fillFirstCol = true;
      break;
    }
  }

  for (int i = 1; i < matrixSize; i++) {
    for (int j = 1; j < *matrixColSize; j++) {
      if (matrix[i][j] == 0) {
        matrix[i][0] = 0;
        matrix[0][j] = 0;
      }
    }
  }

  for (int i = 1; i < matrixSize; i++) {
    for (int j = 1; j < *matrixColSize; j++) {
      if (matrix[i][0] == 0 || matrix[0][j] == 0) {
        matrix[i][j] = 0;
      }
    }
  }

  if (fillFirstRow) {
    for (int i = 0; i < *matrixColSize; i++) {
      matrix[0][i] = 0;
    }
  }

  if (fillFirstCol) {
    for (int i = 0; i < matrixSize; i++) {
      matrix[i][0] = 0;
    }
  }
}