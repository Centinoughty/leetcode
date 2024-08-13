// Minimum difference between largest and smallest value in three moves
// MEDIUM

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int compare (const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int minDifference(int* nums, int numsSize) {
  if (numsSize < 4) {
    return 0;
  }

  int minimum = INT_MAX;
  qsort(nums, numsSize, sizeof(int), compare);
  for (int i = 0; i < 4; i ++) {
    minimum = fmin(minimum, nums[numsSize - 1 - 3 + i] - nums[i]);
  }

  return minimum;
}
