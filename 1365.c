// How many numnbers are smaller than the current number?
// EASY

#include <stdio.h>

int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize) {
    int* array = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;
    for (int i = 0; i < numsSize; i ++) {
        int count = 0;
        for (int j = 0; j < numsSize; j ++) {
            if (nums[i] > nums[j]) {
                count ++;
            }
        }

        array[i] = count;
    }

    return array;
}