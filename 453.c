// Minimum moves to equal array elements
// MEDIUM

#include <stdio.h>
#include <limits.h>

int abs (int n) {
  return n < 0 ? -n : n;
}

int minMoves(int* nums, int numsSize) {
  int minimum = INT_MAX;
  for (int i = 0; i < numsSize; i ++) {
    minimum = minimum > nums[i] ? nums[i] : minimum;
  }

  int count = 0;
  for (int i = 0; i < numsSize; i ++) {
    count += abs(nums[i] - minimum);
  }

  return count;
}
