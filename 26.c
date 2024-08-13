// Remove duplicates from sorted array
// EASY

#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
  int i = 0, j = 1;
  while (i < j && j < numsSize) {
    if (nums[i] == nums[j]) {
      j ++;
    } else {
      nums[++ i] = nums[j ++];
    }
  }

  return i + 1;
}