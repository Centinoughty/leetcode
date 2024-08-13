// Maximum matrix sum
// MEDIUM

#include <stdio.h>
#include <limits.h>

int abs (int n) {
  return n < 0 ? -n : n;
}

long long maxMatrixSum(int** matrix, int matrixSize, int* matrixColSize) {
  long long int absSum = 0;
  int negCount = 0;
  int minimum = INT_MAX;

  for (int i = 0; i < matrixSize; i ++) {
    for (int j = 0; j < *matrixColSize; j ++) {
      absSum += abs(matrix[i][j]);
      minimum = fmin(minimum, abs(matrix[i][j]));
      if (matrix[i][j] < 0) {
        negCount ^= 1;
      }
    }
  }

  return absSum - negCount * minimum * 2;
}