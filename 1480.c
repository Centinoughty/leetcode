// Running sum of 1-D array
// EASY

#include <stdio.h>

int* runningSum(int* nums, int numsSize, int* returnSize){
    int* array = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;
    int sum = 0;
    for (int i = 0; i < numsSize; i ++) {
        array[i] = sum += nums[i];
    }

    return array;
}