// Move zeroes
// EASY

#include <stdio.h>

void moveZeroes(int* nums, int numsSize) {
  int i = 0;
  int j = 0;
  
  for (i = 0; i < numsSize; ++i) {
    if (nums[i] != 0) {
      nums[j ++] = nums[i];
    }
  }
  
  while (j < numsSize) {
    nums[j ++] = 0;
  }
}
