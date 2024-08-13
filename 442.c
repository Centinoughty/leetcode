// Find all duplicates in an array
// MEDIUM

#include <stdio.h>
#include <stdlib.h>

int abs (int n) {
  return n < 0 ? -n : n;
}

int* findDuplicates(int* nums, int numsSize, int* returnSize) {
  int* array = (int*)malloc(numsSize * sizeof(int));
  int pos = 0;

  for (int i = 0; i < numsSize; i ++) {
    nums[abs(nums[i]) - 1] *= -1;
    if (nums[abs(nums[i]) - 1] > 0) {
      array[pos ++] = abs(nums[i]);
    }
  }

  *returnSize = pos;
  return array;
}