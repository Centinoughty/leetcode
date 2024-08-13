// Trapping rain water
// HARD

#include <stdio.h>

int trap (int arr[], int n) {
    int trappedWater = 0;
    int left = 0;
    int right = n - 1;
    int leftMax = arr[left];
    int rightMax = arr[right];

    while (left < right) {
        if (leftMax < rightMax) {
            trappedWater += leftMax - arr[left];
            left += 1;
            leftMax = leftMax > arr[left] ? leftMax : arr[left];
        } else {
            trappedWater += rightMax - arr[right];
            right -= 1;
            rightMax = rightMax > arr[right] ? rightMax : arr[right];
        }
    }

    return trappedWater;
}