// Maximum gap
// MEDIUM

#include <stdio.h>
#include <stdlib.h>

void countSort(int* nums, int numsSize, int pos) {
  int* count = (int*)calloc(10, sizeof(int));
  int* temp = (int*)malloc(numsSize * sizeof(int));

  for (int i = 0; i < numsSize; i ++) {
    count[(nums[i] / pos) % 10] ++;
  }

  for (int i = 1; i < 10; i ++) {
    count[i] += count[i - 1];
  }

  for (int i = numsSize - 1; i >= 0; i --) {
    temp[-- count[(nums[i] / pos) % 10]] = nums[i];
  }

  for (int i = 0; i < numsSize; i ++) {
    nums[i] = temp[i];
  }

  free(count);
  free(temp);
}

void radixSort(int* nums, int numsSize) {
  int maximum = nums[0];
  for (int i = 1; i < numsSize; i ++) {
    maximum = nums[i] > maximum ? nums[i] : maximum;
  }

  int temp = maximum;
  while (temp > 0) {
    temp /= 10;
  }

  for (int i = 1; maximum / i > 0; i *= 10) {
    countSort(nums, numsSize, i);
  }
}

int maximumGap(int* nums, int numsSize) {
  int result = 0;
  radixSort(nums, numsSize);

  for (int i = 1; i < numsSize; i ++) {
    result = fmax(result, nums[i] - nums[i - 1]);
  }

  return result;
}
