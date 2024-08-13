// Minimum number of K consecutive bit flips
// HARD

#include <stdio.h>
#include <stdlib.h>

int minKBitFlips(int* nums, int numsSize, int k) {
  int res = 0;
  int temp = 0;
  
  int* array = (int*)calloc(numsSize, sizeof(int));

  for (int i = 0; i < numsSize; i ++) {
    if (array[i]) {
      temp ^= 1;
    }

    if (nums[i] ^ temp == 0) {
      res ++;
      temp ^= 1;
      if (i + k > numsSize) {
        return -1;
      }
      
      if (i + k < numsSize) {
        array[i + k] = 1;
      }
    }
  }

  return res;
}
