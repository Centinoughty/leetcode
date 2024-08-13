// Transpose matrix
// EASY

#include <stdio.h>
#include <stdlib.h>

int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
    int m = matrixSize, n = *matrixColSize;
    int** array = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i ++) {
        array[i] = (int*)malloc(m * sizeof(int));
        for (int j = 0; j < m; j ++) {
            array[i][j] = matrix[j][i];
        }
    }

    *returnSize = n;
    *returnColumnSizes = malloc(n * sizeof(int));
    for (int i = 0; i < n; i ++) {
        (*returnColumnSizes)[i] = m;
    }

    return array;
}