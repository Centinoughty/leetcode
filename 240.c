// Search a 2D matrix II
// MEDIUM

#include <stdio.h>
#include <stdbool.h>

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int m = matrixSize, n = *matrixColSize;
    for (int i = 0; i < m; i ++) {
        int left = 0;
        int right = n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (matrix[i][mid] == target) {
                return true;
            } else if (matrix[i][mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }

    return false;
}