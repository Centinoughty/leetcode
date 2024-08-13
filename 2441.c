// Largest positive integer that exists with its negative
// EASY

#include <stdio.h>
#include <stdlib.h>

int findMaxK(int* nums, int numsSize) {
    int* array = (int*)malloc(numsSize * sizeof(int));
    int pos = 0;
    for (int i = 0; i < numsSize; i ++) {
        if (nums[i] < 0) {
            array[pos ++] = nums[i];
        }
    }

    for (int i = 1; i < pos; i ++) {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j --;
        }

        array[j + 1] = key;
    }

    for (int i = 0; i < pos; i ++) {
        for (int j = 0; j < numsSize; j ++) {
            if (array[i] + nums[j] == 0) {
                return nums[j];
            }
        }
    }

    return -1;
}