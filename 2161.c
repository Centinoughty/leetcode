// Partition array according to given pivot
// MEDIUM

#include <stdio.h>
#include <stdlib.h>

int* pivotArray(int* nums, int numsSize, int pivot, int* returnSize) {
  int* array = (int*)malloc(numsSize * sizeof(int));
  int pos = 0;

  for(int i = 0; i < numsSize; i ++) {
    if (nums[i] < pivot) {
      array[pos ++] = nums[i];
    }
  }

  for (int i = 0; i < numsSize; i ++) {
    if (nums[i] == pivot) {
      array[pos ++] = nums[i];
    }
  }

  for (int i = 0; i < numsSize; i ++) {
    if (nums[i] > pivot) {
      array[pos ++] = nums[i];
    }
  }

  *returnSize = numsSize;
  return array;
}
