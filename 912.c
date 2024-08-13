// Sort an array
// MEDIUM

#include <stdio.h>

void merge (int* nums, int lb, int ub, int mid) {
  int i = lb, j = mid + 1;
  int pos = 0;
  int B[ub - lb + 1];

  while (i <= mid && j <= ub) {
    if (nums[i] <= nums[j]) {
      B[pos ++] = nums[i ++]; 
    } else {
      B[pos ++] = nums[j ++];
    }
  }

  while (j <= ub) {
    B[pos ++] = nums[j ++];
  }

  while (i <= mid) {
    B[pos ++] = nums[i ++];
  }

  for (int i = lb, k = 0; i <= ub; i ++, k ++) {
    nums[i] = B[k];
  }
}

void mergeSort (int* nums, int lb, int ub) {
  if (lb < ub) {
    int mid = (lb + ub) / 2;
    mergeSort(nums, lb, mid);
    mergeSort(nums, mid + 1, ub);
    merge(nums, lb, ub, mid);
  }
}


int* sortArray(int* nums, int numsSize, int* returnSize) {
  int* array = (int*)malloc(numsSize * sizeof(int));

  for (int i = 0; i < numsSize; i ++) {
    array[i] = nums[i];
  }

  mergeSort(array, 0, numsSize - 1);
  *returnSize = numsSize;
  return array;
}