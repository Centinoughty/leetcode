// Max consecutive ones
// EASY

#include <stdio.h>

int findMaxConsecutiveOnes(int* nums, int numsSize) {
  int maxCount = 0;
  int count = 0;
  for (int i = 0; i < numsSize; i ++) {
    if (nums[i] == 1) {
      count ++;
    } else {
      maxCount = fmax(maxCount, count);
      count = 0;
    }
  }
  
  maxCount = fmax(maxCount, count);
  return maxCount;
}