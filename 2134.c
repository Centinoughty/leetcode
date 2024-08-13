// Minimum swaps to group all 1's together II
// MEDIUM

#include <stdio.h>

int minSwaps(int* nums, int numsSize) {
  int countOnes = 0;
  int temp = 0;
  int maxCount = 0;

  for (int i = 0; i < numsSize; i ++) {
    if (nums[i] == 1) {
      countOnes ++;
    }
  }

  for (int i = 0; i < countOnes; i ++) {
    if (nums[i] == 1) {
      temp ++;
    }
  }

  int i = 0;
  int j = countOnes - 1;

  while (j < numsSize + countOnes -1) {
    if (nums[(i ++) % numsSize] == 1) {
      temp --;
    }

    if (nums[(++ j) % numsSize] == 1) {
      temp ++;
    }

    maxCount = fmax(maxCount, temp);
  }

  return countOnes - maxCount;
}
