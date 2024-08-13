// Concatenation of array

#include <stdio.h>

int* getConcatenation(int* nums, int numsSize, int* returnSize) {
    int* array = (int*)malloc(2 * numsSize * sizeof(int));
    *returnSize = 2 * numsSize;
    for (int i = 0; i < numsSize; i ++) {
        array[i] = nums[i];
        array[i + numsSize] = nums[i];
    }

    return array;
}