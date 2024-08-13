// 01 Matrix
// MEDIUM

#include <stdio.h>
#include <stdlib.h>

int** updateMatrix(int** mat, int matSize, int* matColSize, int* returnSize, int** returnColumnSizes) {
    int m = matSize, n = *matColSize;
    int** array = (int**)malloc(m * sizeof(int*));
    *returnColumnSizes = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < m; i ++) {
        array[i] = (int*)malloc(n * sizeof(int));
        (*returnColumnSizes)[i] = n;
        for (int j = 0; j < n; j ++) {
            array[i][j] = m + n;
        }
    }

    for (int i = 0; i < m; i ++) {
        for (int j = 0; j < n; j ++) {
            if (mat[i][j] == 0) {
                array[i][j] = 0;
            } else {
                if (i > 0) {
                    array[i][j] = fmin(array[i][j], array[i - 1][j] + 1);
                }
                if (j > 0) {
                    array[i][j] = fmin(array[i][j], array[i][j - 1] + 1);
                }
            }
        }
    }

    for (int i = m - 1; i >= 0; i --) {
        for (int j = n - 1; j >= 0; j --) {
            if (i < m - 1) {
                array[i][j] = fmin(array[i][j], array[i + 1][j] + 1);
            }
            if (j < n - 1) {
                array[i][j] = fmin(array[i][j], array[i][j + 1] + 1);
            }
        }
    }

    *returnSize = m;
    return array;
}