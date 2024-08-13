// Find the duplicate number
// MEDIUM

#include <stdio.h>

int findDuplicate(int* nums, int numsSize) {
    int x = nums[0], y = nums[0];
    do {
        x = nums[x];
        y = nums[nums[y]];
    } while (x != y);

    int i = nums[0];
    int j = x;
    while (i != j) {
        i = nums[i];
        j = nums[j];
    }

    return i;
}