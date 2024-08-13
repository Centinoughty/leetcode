// Score after flipping matrix
// MEDIUM

#include <stdio.h>

int matrixScore(int** grid, int gridSize, int* gridColSize) {
    for (int i = 0; i < gridSize; i ++) {
        if (grid[i][0] == 0) {
            for (int j = 0; j < *gridColSize; j ++) {
                grid[i][j] = 1 - grid[i][j];
            }
        }
    }

    for (int j = 1; j < *gridColSize; j ++) {
        int count = 0;
        for (int i = 0; i < gridSize; i ++) {
            count += grid[i][j];
        }

        if (count <= gridSize / 2) {
            for (int i = 0; i < gridSize; i ++) {
                grid[i][j] = 1 - grid[i][j];
            }
        }
    }

    int score = 0;
    for (int i = 0; i < gridSize; i ++) {
        for (int j = 0; j < *gridColSize; j ++) {
            score += grid[i][j] * (1 << (*gridColSize - j - 1));
        }
    }

    return score;
}