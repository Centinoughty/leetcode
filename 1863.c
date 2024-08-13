// Sum of all subset XOR total
// EASY

#include <stdio.h>

int subsetXORSum(int* nums, int numsSize) {
    int result = 0;
    for (int i = 0; i < numsSize; i ++) {
        result |= nums[i];
    }

    return result << (numsSize - 1);
}