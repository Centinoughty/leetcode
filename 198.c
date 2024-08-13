// House robber
// MEDIUM

#include <stdio.h>
#include <stdlib.h>

int rob(int* nums, int numsSize) {
  if (numsSize == 1) {
    return nums[0];
  }

  int* array = (int*)malloc(numsSize * sizeof(int));
  array[0] = nums[0];
  array[1] = fmax(nums[0], nums[1]);
  
  for (int i = 2; i < numsSize; i ++) {
    array[i] = fmax(array[i - 1], array[i - 2] + nums[i]);
  }

  return array[numsSize - 1];
}
