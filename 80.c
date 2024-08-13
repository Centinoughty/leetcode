// Remove duplicates from sorted array II
// MEDIUM

#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize <= 2) {
        return numsSize;
    }
    
    int i = 2;
    for (int j = 2; j < numsSize; j ++) {
        if (nums[j] != nums[i - 2]) {
            nums[i ++] = nums[j];
        }
    }

    return i;
}