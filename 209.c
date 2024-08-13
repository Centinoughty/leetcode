// Minimum size subarray sum
// MEDIUM

#include <stdio.h>

int minSubArrayLen(int target, int* nums, int numsSize) {
  int start = 0;
  int sum = 0;
  int minLength = numsSize + 1;
  for (int i = 0; i < numsSize; i ++) {
    sum += nums[i];
    while (sum >= target) {
      minLength = minLength > i - start + 1 ? i - start + 1 : minLength;
      sum -= nums[start ++];
    }
  }

  return minLength == numsSize + 1 ? 0 : minLength;
}