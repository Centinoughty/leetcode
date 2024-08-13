// Remove element
// EASY

#include <stdio.h>

void swap (int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int removeElement(int* nums, int numsSize, int val) {
  int left = 0, right = numsSize - 1;

  if (numsSize == 0) {
    return 0;
  } else if (numsSize == 1 && nums[0] == val) {
    return 0;
  }

  while (left <= right) {
    if (nums[right] == val) {
      right --;
    } else if (nums[left] == val) {
      swap(&nums[left ++], &nums[right --]);
    } else {
      left ++;
    }
  }

  return left;
}