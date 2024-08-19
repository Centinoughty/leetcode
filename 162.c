// Find peak element
// MEDIUM

#include <stdio.h>

int findPeakElement(int* nums, int numsSize) {
  for (int i = 1; i < numsSize - 1; i ++) {
    if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
      return i;
    }
  }

  if (numsSize > 1) {
    if (nums[0] > nums[1]) {
      return 0;
    }

    if (nums[numsSize - 1] > nums[numsSize - 2]) {
      return numsSize - 1;
    }
  }

  return 0;
}
