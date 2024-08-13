// Unique paths-II
// MEDIUM

#include <stdio.h>

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize) {
    int m = obstacleGridSize;
    int n = *obstacleGridColSize;
    int array[m][n];
    array[0][0] = obstacleGrid[0][0] == 0 ? 1 : 0;
    for (int i = 1; i < m; i ++) {
        if (obstacleGrid[i][0] == 0 && array[i - 1][0] == 1) {
            array[i][0] = 1;
        } else {
            array[i][0] = 0;
        }
    }

    for (int i = 1; i < n; i ++) {
        if (obstacleGrid[0][i] == 0 && array[0][i - 1] == 1) {
            array[0][i] = 1;
        } else {
            array[0][i] = 0;
        }
    }

    for (int i = 1; i < m; i ++) {
        for (int j = 1; j < n; j ++) {
            if (obstacleGrid[i][j] == 0) {
                array[i][j] = array[i - 1][j] + array[i][j - 1];
            } else {
                array[i][j] = 0;
            }
        }
    }

    return array[m - 1][n - 1];
}