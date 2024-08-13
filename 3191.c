// Minimum operations to make binary array elements equal to one I
// MEDIUM

#include <stdio.h>

int minOperations(int* nums, int numsSize) {
  int count = 0;
  for (int i = 0; i < numsSize - 2; i ++) {
    if (nums[i] == 0) {
      nums[i] = 1;
      nums[i + 1] = !nums[i + 1];
      nums[i + 2] = !nums[i + 2];
      count ++;
    }
  }
  
  if (nums[numsSize - 1] == 0 || nums[numsSize - 2] == 0) {
    return -1;
  }
  
  return count;
}