// Subsets
// MEDIUM

#include <stdio.h>
#include <stdlib.h>

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
  int total = 1 << numsSize;
  int** array = (int**)malloc(total * sizeof(int*));
  *returnSize = total;
  *returnColumnSizes = (int*)malloc(total * sizeof(int));

  for (int i = 0; i < (1 << numsSize); i ++) {
    array[i] = (int*)malloc(total * sizeof(int));
    int pos = 0;
    for (int j = 0; j < numsSize; j ++) {
      if ((1 << j) & i) {
        array[i][pos ++] = nums[j];
      }
    }

    (*returnColumnSizes)[i] = pos;
  }

  return array;
}
