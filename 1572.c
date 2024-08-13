// Matrix diagonal sum
// EASY

#include <stdio.h>

int diagonalSum(int** mat, int matSize, int* matColSize) {
  int result = 0;
  for (int i = 0; i < matSize; i ++) {
    result += i != matSize - i - 1 ? mat[i][i] + mat[i][matSize - i - 1] : mat[i][i];
  }

  return result;
}