// Product of array except self
// MEDIUM

#include <stdio.h>
#include <stdlib.h>

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int* array = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;
    int prefix = 1;
    for (int i = 0; i < numsSize; i ++) {
        array[i] = prefix;
        prefix *= nums[i];
    }

    int suffix = 1;
    for (int i = numsSize - 1; i >= 0; i --) {
        array[i] *= suffix;
        suffix *= nums[i];
    }

    return array;
}