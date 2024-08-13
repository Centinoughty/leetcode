// Minimum nuumber of operations to make array XOR equal to k
// MEDIUM

#include <stdio.h>

int minOperations(int* nums, int numsSize, int k) {
  int value = 0;

  for (int i = 0; i < numsSize; i ++) {
    value ^= nums[i];
  }

  if (value == k) {
    return 0;
  }
  
  int diff = value ^ k;
  int count = 0;
  while (diff) {
    count += diff & 1;
    diff >>= 1;
  }

  return count;
}