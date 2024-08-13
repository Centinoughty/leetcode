// 4Sum
// MEDIUM

#include <stdio.h>

int compare (const void* a, const void* b) {
  return (*(int*)a - *(int*)b);
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
  qsort(nums, numsSize, sizeof(int), compare);

  int** array = (int**)malloc(numsSize * numsSize * sizeof(int*));
  int pos = 0;

  for (int i = 0; i < numsSize - 3; i ++) {
    if (i > 0 && nums[i] == nums[i - 1]) {
      continue;
    }

    for (int j = i + 1; j < numsSize - 2; j ++) {
      if (j > i + 1 && nums[j] == nums[j - 1]) {
        continue;
      }

      int left = j + 1;
      int right = numsSize - 1;
      while (left < right) {
        long long int sum = (long long int)nums[i] + nums[j] + nums[left] + nums[right];
        if (sum == target) {
          array[pos] = (int*)malloc(4 * sizeof(int));
          array[pos][0] = nums[i];
          array[pos][1] = nums[j];
          array[pos][2] = nums[left];
          array[pos][3] = nums[right];

          while (left < right && nums[left] == nums[left + 1]) {
            left ++;
          }

          while (left < right && nums[right] == nums[right - 1]) {
            right --;
          }

          left ++;
          right --;
          pos ++;
        } else if (sum < target) {
          left ++;
        } else {
          right --;
        }
      }
    }
  }

  *returnSize = pos;
  *returnColumnSizes = (int*)malloc(pos * sizeof(int));
  for (int i = 0; i < pos; i ++) {
    (*returnColumnSizes)[i] = 4;
  }

  return array;
}