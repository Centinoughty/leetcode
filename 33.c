// Search in rotated sorted array
// MEDIUM

#include <stdio.h>

int search(int* nums, int numsSize, int target) {
    int l = 0;
    int r = numsSize - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] == target) {
            return mid;
        }

        if (nums[l] < nums[mid]) {
            if (nums[l] <= target && target < nums[mid]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        } else if (nums[l] > nums[mid]) {
            if (nums[mid] < target && target <= nums[r]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        } else {
            l ++;
        }
    }

    return -1;
}