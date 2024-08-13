// Single number III
// MEDIUM

#include <stdio.h>
#include <stdlib.h>

int* singleNumber(int* nums, int numsSize, int* returnSize) {
  int* array = (int*)calloc(2, sizeof(int));
  long int xor = 0;
  for (int i = 0; i < numsSize; i ++) {
    xor ^= nums[i];
  }

  long int bit = xor & (-xor);
  for (int i = 0; i < numsSize; i ++) {
    if (nums[i] & bit) {
      array[0] ^= nums[i];
    } else {
      array[1] ^= nums[i];
    }
  }

  *returnSize = 2;
  return array;
}