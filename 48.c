// Rotate image
// MEDIUM

#include <stdio.h>

void swap (int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    int m = matrixSize;
    for (int i = 0; i < m / 2; i ++) {
        for (int j = 0; j < m; j ++) {
            swap(&matrix[i][j], &matrix[m - i - 1][j]);
        }
    }

    int pos = 1;
    for (int i = 0; i < m; i ++) {
        for(int j = pos; j < m; j ++) {
            swap(&matrix[i][j], &matrix[j][i]);
        }

        pos ++;
    }
}