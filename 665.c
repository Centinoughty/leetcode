// Non-decreasing array
// MEDIUM

#include <stdio.h>
#include <stdbool.h>

bool checkPossibility(int* nums, int numsSize) {
    int count = 0;
    for (int i = 0; i < numsSize - 1; i ++) {
        if (nums[i] > nums[i + 1]) {
            count ++;
            if (i > 0 && i + 2 < numsSize && nums[i - 1] > nums[i + 1] && nums[i] > nums[i + 2]) {
                count ++;
            }
        }
    }

    return count > 1 ? false : true;
}