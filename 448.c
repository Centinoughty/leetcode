// Find all numbers disappeared in an array
// EASY

#include <stdio.h>

int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
  int* array = (int*)calloc(numsSize, sizeof(int));
  int* result = (int*)malloc(numsSize * sizeof(int));
  int pos = 0;

  for (int i = 0; i < numsSize; i ++) {
    array[nums[i] - 1] += 1;
  }

  for (int i = 0; i < numsSize; i ++) {
    if (array[i] == 0) {
      result[pos ++] = i + 1;
    }
  }

  free(array);
  *returnSize = pos;
  return result;
}