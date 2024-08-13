// Subarray sums divisible by k
// MEDIUM

#include <stdio.h>
#include <stdlib.h>

int subarraysDivByK(int* nums, int numsSize, int k) {
  int* array = (int*)calloc(k, sizeof(int));
  int count = 0;
  int prefix = 0;
  
  for (int i = 0; i < numsSize; i ++) {
    prefix += nums[i];
    int rem = (prefix % k + k) % k;

    if (rem == 0) {
      count ++;
    }

    count += array[rem];
    array[rem] ++;
  }

  free(array);
  return count;
}