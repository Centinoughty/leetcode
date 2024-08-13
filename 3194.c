// Minimum average of smallest and largest elements
// EASY

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int compare (const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

double minimumAverage(int* nums, int numsSize) {
  double min = INT_MAX;
  qsort(nums, numsSize, sizeof(int), compare);
  
  int l = 0, r = numsSize - 1;
  
  while (l < r) {
    min = fmin(min, (double)(nums[l] + nums[r]) / 2);
    l ++;
    r --;
  }
  
  return min;
}
