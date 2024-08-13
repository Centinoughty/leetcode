// Search in rotated sorted array II
// MEDIUM

#include <stdio.h>
#include <stdbool.h>

bool search(int* nums, int numsSize, int target) {
  int left = 0;
  int right = numsSize - 1;

  while (left <= right) {
    int mid = (left + right) / 2;
    
    if (nums[mid] == target) {
      return true;
    }

    if (nums[mid] == nums[left] && nums[mid] == nums[right]) {
      left ++;
      right --;
    } else if (nums[left] <= nums[mid]) {
      if (nums[left] <= target && target <= nums[mid]) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    } else {
      if (nums[mid] <= target && target <= nums[right]) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
  }

  return false;
}