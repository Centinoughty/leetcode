// Check if array pairs are divisible by k
// MEDIUM

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool canArrange(int* arr, int arrSize, int k) {
  int* nums = (int*)calloc(k, sizeof(int));
  for (int i = 0; i < arrSize; i ++) {
    nums[((arr[i] % k) + k) % k] ++;
  }

  if (nums[0] % 2 != 0) {
    return false;
  }

  for (int i = 1; i <= k / 2; i ++) {
    if (nums[i] != nums[k - i]) {
      return false;
    }
  }

  return true;
}
