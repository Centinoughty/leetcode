// Find minimum operations to make all elements divisible by three
// EASY

#include <stdio.h>

int minimumOperations(int* nums, int numsSize) {
  int res = 0;
  for (int i = 0; i < numsSize; i ++) {
    if (nums[i] % 3 != 0) {
      res += fmin(nums[i] % 3, 3 - nums[i] % 3);
    }
  }
  
  return res;
}
