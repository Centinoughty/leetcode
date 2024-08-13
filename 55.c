// Jump game
// MEDIUM

#include <stdio.h>
#include <stdbool.h>

bool canJump(int* nums, int numsSize) {
    int maximum = 0;
    for (int i = 0; i < numsSize; i++) {
        if (i > maximum) {
            return false;
        }

        maximum = (i + nums[i]) > maximum ? (i + nums[i]) : maximum;
        if (maximum >= numsSize - 1) {
            return true;
        }
    }
    return false;
}