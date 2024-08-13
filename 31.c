// Next permutation
// MEDIUM

#include <stdio.h>

void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void reverse (int* nums, int start, int end) {
  while (start < end) {
    swap(&nums[start], &nums[end]);
    start ++;
    end --;
  }
}

void nextPermutation(int* nums, int numsSize) {
  int right = numsSize - 2;
  while (right >= 0 && nums[right] >= nums[right + 1]) {
    right --;
  }

  if (right >= 0) {
    int i = numsSize - 1;
    while (i >= 0 &&  nums[i] <= nums[right]) {
      i --;
    }

    swap(&nums[right], &nums[i]);
  }

  reverse(nums, right + 1, numsSize - 1);
}