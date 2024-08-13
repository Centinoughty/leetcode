// Minimum opeartions to exceed the threshold value k
// EASY

#include <stdio.h>

int minOperations(int* nums, int numsSize, int k) {
    int count = 0;
    for (int i = 0; i < numsSize; i ++) {
        if (nums[i] < k) {
            count ++;
        }
    }

    return count;
}