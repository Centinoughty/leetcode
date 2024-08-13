// Largest local values in a matrix
// EASY

#include <stdio.h>
#include <stdlib.h>

int findMax (int A[]) {
    int max = A[0];
    for (int i = 1;i < 9; i ++) {
        if (A[i] > max) {
            max = A[i];
        }
    }

    return max;
}


int** largestLocal(int** grid, int gridSize, int* gridColSize, int* returnSize, int** returnColumnSizes) {
    int** array = (int**)malloc((gridSize - 2) * sizeof(int*));
    *returnSize = gridSize - 2;
    *returnColumnSizes = (int*)malloc((gridSize - 2) * sizeof(int));
    for (int i = 0; i < gridSize - 2; i ++) {
        array[i] = (int*)malloc((*gridColSize - 2) * sizeof(int));
        (*returnColumnSizes)[i] = *gridColSize - 2;
    }

    for (int i = 1; i < gridSize - 1; i ++) {
        for (int j = 1; j < *gridColSize - 1; j ++) {
            int subMatrix[] = {grid[i - 1][j - 1], grid[i][j - 1], grid[i + 1][j - 1],
                    grid[i - 1][j], grid[i][j], grid[i + 1][j],
                    grid[i - 1][j + 1], grid[i][j + 1], grid[i + 1][j + 1]
                    };

            array[i - 1][j - 1] = findMax(subMatrix);
        }
    }

    return array;
}