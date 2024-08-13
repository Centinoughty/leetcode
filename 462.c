// Minimum moves to equal array elements II
// MEDIUM

#include <stdio.h>
#include <stdlib.h>

int abs (int n) {
  return n < 0 ? -n : n;
}

int compare (const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int minMoves2(int* nums, int numsSize) {
  qsort(nums, numsSize, sizeof(int), compare);

  int median = numsSize % 2 ? nums[numsSize / 2] : (nums[numsSize / 2] + nums[numsSize / 2 - 1]) / 2;

  int count = 0;
  for (int i = 0; i < numsSize; i ++) {
    count += abs(nums[i] - median);
  }

  return count;
}