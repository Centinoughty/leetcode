// Search a 2D matrix
// MEDIUM

#include <stdio.h>
#include <stdbool.h>

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int m = matrixSize, n = *matrixColSize;
    int left = 0;
    int right = m * n - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        int i = mid / n;
        int j = mid % n;
        if (matrix[i][j] == target) {
            return true;
        } else if (matrix[i][j] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return false;
}