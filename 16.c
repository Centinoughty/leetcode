// 3Sum closest
// MEDIUM

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int compare (const void* a, const void* b) {
  return (*(int*)a - *(int*)b);
}

int threeSumClosest(int* nums, int numsSize, int target) {
  qsort(nums, numsSize, sizeof(int), compare);

  int minimumDiff = INT_MAX;
  int closestSum = INT_MAX;
  for (int i = 0; i < numsSize - 2; i ++) {
    int left = i + 1;
    int right = numsSize - 1;
    while (left < right) {
      int sum = nums[i] + nums[left] + nums[right];
      int diff = abs(sum - target);
      if (diff < minimumDiff) {
        minimumDiff = diff;
        closestSum = sum;
      }

      if (sum < target) {
        left ++;
      } else if (sum > target) {
        right --;
      } else {
        return sum;
      }
    }
  }

  return closestSum;
}