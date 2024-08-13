// Jump game II
// MEDIUM

#include <stdio.h>

int jump(int* nums, int numsSize) {
  if (numsSize == 1) {
    return 0;
  }

  int result = 0;
  int end = 0;
  int last = 0;

  for (int i = 0; i < numsSize; i ++) {
    last = fmax(last, i + nums[i]);
    if (last >= numsSize - 1) {
      result ++;
      break;
    }

    if (i == end) {
      result ++;
      end = last;
    }
  }

  return result;
}
