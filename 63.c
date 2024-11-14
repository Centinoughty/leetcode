// Unique paths-II
// MEDIUM

#include <stdio.h>
#include <stdlib.h>

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize) {
	int** grid = (int**)malloc(obstacleGridSize * sizeof(int*));
	for (int i = 0; i < obstacleGridSize; i ++) {
		grid[i] = (int*)calloc(*obstacleGridColSize, sizeof(int));
	}
	
	for (int i = 0; i < obstacleGridSize; i ++) {
		if (!obstacleGrid[i][0]) {
			grid[i][0] = 1;
		} else {
			break;
		}
	}

	for (int j = 0; j < *obstacleGridColSize; j ++) {
		if (!obstacleGrid[0][j]) {
			grid[0][j] = 1;
		} else {
			break;
		}
	}

	for (int i = 1; i < obstacleGridSize; i ++) {
		for (int j = 1; j < *obstacleGridColSize; j ++) {
			if (!obstacleGrid[i][j]) {
				grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
			} else {
				grid[i][j] = 0;
			}
		}
	}

	return grid[obstacleGridSize - 1][*obstacleGridColSize - 1];
}
