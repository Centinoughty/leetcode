// Shuffle the array

#include <stdio.h>

int* shuffle(int* nums, int numsSize, int n, int* returnSize){
    int* array = (int*)malloc(numsSize * sizeof(int));
    for (int i = 0; i < n; i ++) {
        array[2 * i] = nums[i];
        array[2 * i + 1] = nums[i + n];
    }

    *returnSize = numsSize;
    return array;
}