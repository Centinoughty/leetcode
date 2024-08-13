// Check if array is sorted
// EASY

#include <stdio.h>
#include <stdbool.h>

bool check(int* nums, int numsSize) {
    int result = 0;
    for (int i = 0; i < numsSize; i ++) {
        if (nums[i] > nums[(i + 1) % numsSize] && ++ result > 1) {
            return false;
        }
    }

    return true;
}