// The number of beutiful subsets
// MEDIUM

#include <stdio.h>
#include <stdbool.h>

int beautifulSubsets(int* nums, int numsSize, int k) {
    int total = 1 << numsSize;
    int count = 0;

    for (int i = 1; i < total; i++) {
        bool valid = true;

        for (int j = 0; j < numsSize - 1; j++) {
            for (int l = j + 1; l < numsSize; l++) {
                if ((i & (1 << j)) && (i & (1 << l)) && abs(nums[j] - nums[l]) == k) {
                    valid = false;
                    break;
                }
            }
            if (!valid) {
                break;
            }
        }

        if (valid) {
            count++;
        }
    }

    return count;
}