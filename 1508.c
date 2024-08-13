// Range sum of sorted subarray sums
// MEDIUM

#include <stdio.h>
#include <stdlib.h>

int compare (const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int rangeSum(int* nums, int numsSize, int n, int left, int right) {
  int totalCount = (n * (n + 1)) / 2;
  long long res = 0;
  int* array = (int*)malloc(totalCount * sizeof(int));
  int pos = 0;

  for (int i = 0; i < numsSize; i ++) {
    int val = 0;
    for (int j = i; j < numsSize; j ++) {
      val += nums[j];
      array[pos ++] = val;
    }
  }

  qsort(array, totalCount, sizeof(int), compare);

  for (int i = left - 1; i < right; i ++) {
    res += array[i];
  }

  return res % (1000000007);
}
