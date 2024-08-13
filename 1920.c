// Build array from permutation

#include <stdio.h>

int* buildArray(int* nums, int numsSize, int* returnSize) {
    int* array = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;
    for (int i = 0; i < numsSize; i ++) {
        array[i] = nums[nums[i]];
    }

    return array;
}