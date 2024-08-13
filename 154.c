// Find minimum in rotated sorted array II
// HARD

#include <stdio.h>

int findMin(int* nums, int numsSize) {
  int left = 0, right = numsSize - 1;
  
  while (left < numsSize - 1 && nums[left] == nums[left + 1]) {
    left ++;
  }

  while (right > 0 && nums[right] == nums[right - 1]) {
    right --;
  }

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