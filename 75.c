// Sort colors
// MEDIUM

#include <stdio.h>

void swap (int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortColors(int* nums, int numsSize) {
  int left = 0, right = numsSize - 1;
  for (int i = 0; i <= right;) {
    if (nums[i] == 0) {
      swap(&nums[i ++], &nums[left ++]);
    } else if (nums[i] == 1) {
      i ++;
    } else {
      swap(&nums[i], &nums[right --]);
    }
  }
}