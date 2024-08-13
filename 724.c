// Find pivot index
// EASY

#include <stdio.h>
#include <stdlib.h>

int pivotIndex(int* nums, int numsSize) {
  int* array = (int*)calloc(numsSize + 2, sizeof(int));

  for (int i = 1; i < numsSize + 1; i ++) {
    array[i] = array[i - 1] + nums[i - 1];
  }

  for (int i = 1; i < numsSize + 1; i ++) {
    if (array[i - 1] == array[numsSize] - array[i]) {
      return i - 1;
    }
  }

  free(array);
  return -1;
}