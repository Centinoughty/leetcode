// Find minimum in rotated sorted array
// MEDIUM

#include <stdio.h>

int findMin(int* nums, int numsSize) {
  int left = 0, right = numsSize - 1;

  while (left <= right) {
    int mid = (left + right) / 2;
    if (nums[mid] > nums[right]) {
      left = mid + 1;
    } else if (nums[mid] < nums[right]) {
      right = mid;
    } else {
      right --;
    }
  }

  return nums[left];
}