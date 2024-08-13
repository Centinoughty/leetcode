// Patching array
// HARD

#include <stdio.h>

int minPatches(int* nums, int numsSize, int n) {
  int result = 0;
  int i = 0;
  long int miss = 1;

  while (miss <= n) {
    if (i < numsSize && nums[i] <= miss) {
      miss += nums[i ++];
    } else {
      miss += miss;
      result ++;
    }
  }

  return result;
}