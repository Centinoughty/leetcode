// Monotonic array
// EASY

#include <stdio.h>
#include <stdbool.h>

bool isMonotonic(int* nums, int numsSize) {
  bool inc = true;
  bool dec = true;

  for (int i = 1; i < numsSize; i ++) {
    if (nums[i] > nums[i - 1]) {
      dec = false;
    } else if (nums[i] < nums[i - 1]) {
      inc = false;
    }
  }

  return inc || dec;
}