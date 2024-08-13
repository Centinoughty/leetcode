// Maximum strength of a group
// MEDIUM

#include <stdio.h>

long long maxStrength(int* nums, int numsSize){
    int* negative = malloc(numsSize * sizeof(int));
    int* positive = malloc(numsSize * sizeof(int));
    int posCount = 0, negCount = 0, zeroCount = 0;
    long long int resultX = 1, resultY = 1;
    int x = 0, y = 0;
    for (int i = 0; i < numsSize; i ++) {
        if (nums[i] < 0) {
            negative[negCount ++] = nums[i];
            resultY *= nums[i];
        } else if (nums[i] > 0) {
            positive[posCount ++] = nums[i];
            resultX *= nums[i];
        } else {
            zeroCount ++;
        }
    }

    if (negCount % 2 == 1) {
        int maximum = negative[0];
        for (int i = 0; i < negCount; i ++) {
            if (negative[i] > maximum) {
                maximum = negative[i];
            }
        }

        resultY /= maximum;
    }

    if (numsSize == 1) {
        return nums[0];
    } else if (posCount == 0 && negCount == 1) {
        return 0;
    } else if (posCount == 0 && negCount == 0) {
        return 0;
    }

    return resultX * resultY;
}