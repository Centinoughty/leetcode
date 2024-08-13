// Minimum increment to make array unique
// MEDIUM

#include <stdio.h>
#include <stdlib.h>

int compare (const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int minIncrementForUnique(int* nums, int numsSize) {
  qsort(nums, numsSize, sizeof(int), compare);
  int count = 0;

  for (int i = 1; i < numsSize; i ++) {
    while (nums[i] <= nums[i - 1]) {
      nums[i] ++;
      count ++;
    }
  }

  return count;
}