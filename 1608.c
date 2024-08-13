// Special array with X elements greater than or equal to X
// EASY

#include <stdio.h>

int compare (const void* a, const void* b) {
  return (*(int*)a - *(int*)b);
}

int specialArray(int* nums, int numsSize) {
  qsort(nums, numsSize, sizeof(int), compare);
  int left = 0;
  int right = numsSize - 1;
  while (left <= right) {
    int mid = (left + right) / 2;
    if (nums[mid] >= numsSize - mid) {
      if (mid == 0 || nums[mid - 1] < numsSize - mid) {
        return numsSize - mid;
      } else {
        right = mid - 1;
      }
    } else {
      left = mid + 1;
    }
  }

  return -1;
}