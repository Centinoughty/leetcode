// Letf and right sum difference
// EASY

#include <stdio.h>
#include <stdlib.h>

int* leftRightDifference(int* nums, int numsSize, int* returnSize){
    int* left = (int*)malloc(numsSize * sizeof(int));
    int* right = (int*)malloc(numsSize * sizeof(int));
    int* array = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;

    int sum = 0;
    for (int i = 0; i < numsSize; i ++) {
        left[i] = sum;
        sum += nums[i];
    }

    sum = 0;
    for (int i = numsSize - 1; i >= 0; i --) {
        right[i] = sum;
        sum += nums[i];
    }

    for (int i = 0; i < numsSize; i ++) {
        array[i] = left[i] > right[i] ? left[i] - right[i] : right[i] - left[i];
    }

    return array;
}