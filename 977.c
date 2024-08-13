// Squares of a sorted array
// EASY

#include <stdio.h>
#include <stdlib.h>

int compare (const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int* sortedSquares(int* nums, int numsSize, int* returnSize) {
  for (int i = 0; i < numsSize; i ++) {
    nums[i] *= nums[i];
  }

  qsort(nums, numsSize, sizeof(int), compare);

  *returnSize = numsSize;
  return nums;
}

// Alternate solution

int abs (int n) {
  return n < 0 ? -n : n;
}

int* sortedSquares(int* nums, int numsSize, int* returnSize) {
  int* array = (int*)malloc(numsSize * sizeof(int));
  int pos = numsSize - 1;

  int left = 0;
  int right = numsSize - 1;

  while (left <= right) {
    if (abs(nums[left]) > abs(nums[right])) {
      array[pos --] = nums[left] * nums[left ++];
    } else {
      array[pos --] = nums[right] * nums[right --];
    }
  }

  *returnSize = numsSize;
  return array;
}