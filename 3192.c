// Minimum operations to make binary array elements equal to one II
// MEDIUM

#include <stdio.h>

int minOperations(int* nums, int numsSize) {
  int current = 0;
  int res = 0;

  for (int i = 0; i < numsSize; i ++) {
    if (nums[i] ^ current == 0) {
      res ++;
      current ^= 1;
    }
  }

  return res;
}
 