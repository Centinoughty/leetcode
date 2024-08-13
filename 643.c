// Maximum average subarray I
// EASY

#include <stdio.h>

double findMaxAverage(int* nums, int numsSize, int k) {
  int maxSum = 0;
  int current = 0;

  for (int i = 0; i < k; i ++) {
    current += nums[i];
  }

  maxSum = current;

  for (int i = k; i < numsSize; i ++) {
    current += nums[i] - nums[i - k];
    maxSum = maxSum > current ? maxSum : current;
  }

  return (double)maxSum / k;
} 