// Count number of nice subarrays
// MEDIUM

#include <stdio.h>

int numberOfSubarrays(int* nums, int numsSize, int k){
  int res = 0;
  int l = 0, m = 0, r = 0;
  int oddCount = 0;

  for (int i = 0; i < numsSize; i ++) {
    if (nums[i] % 2) {
      oddCount ++;
    }

    while (oddCount > k) {
      if (nums[l] % 2) {
        oddCount --;
      }

      l ++;
      m = l;
    }

    if (oddCount == k) {
      while (nums[m] % 2 == 0) {
        m ++;
      }

      res += m - l + 1;
    }
  }

  return res;
}
