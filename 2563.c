// Count the number of fair pairs
// MEDIUM

#include <stdio.h>
#include <stdlib.h>

int compare (const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

long long count (int* nums, int numsSize, int value) {
  long long count = 0;
  int left = 0, right = numsSize - 1;

  while (left < right) {
    while (left < right && nums[left] + nums[right] > value) {
      right --;
    }

    count += right - left;
    left ++;
  }

  return count;
}

long long countFairPairs(int* nums, int numsSize, int lower, int upper){
  qsort(nums, numsSize, sizeof(int), compare);

  return count(nums, numsSize, upper) - count(nums, numsSize, lower - 1);
}
