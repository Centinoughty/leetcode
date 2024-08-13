// Find first and last position of element in sorted array
// MEDIUM

#include <stdio.h>
#include <stdlib.h>

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int l = 0, r = numsSize - 1;
    int* array = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    array[0] = array[1] = -1;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (nums[mid] == target) {
            array[0] = mid;
            r = mid - 1;
        } else if (nums[mid] > target) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    l = 0;
    r = numsSize - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (nums[mid] == target) {
            array[1] = mid;
            l = mid + 1;
        } else if (nums[mid] > target) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    return array;
}