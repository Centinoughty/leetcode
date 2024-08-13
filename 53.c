// Maximum subarray
// MEDIUM

#include <stdio.h>

int maxSubArray(int* nums, int numsSize) {
  int max = nums[0];
  int temp = nums[0];
  for (int i = 1; i < numsSize; i ++) {
    temp = temp > 0 ? temp + nums[i] : nums[i];
    max = temp > max ? temp : max;
  }

  return max;
}