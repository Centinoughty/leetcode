// Single number

#include <stdio.h>

int singleNumber(int* nums, int numsSize) {
    int required = 0;
    for (int i = 0; i < numsSize; i ++) {
        required ^= nums[i];
    }

    return required;
}
