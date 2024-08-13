// Find the integer added to array I
// EASY

#include <stdio.h>
#include <limits.h>

int addedInteger(int* nums1, int nums1Size, int* nums2, int nums2Size) {
  int min1 = INT_MAX, min2 = INT_MAX;

  for (int i = 0; i < nums1Size; i ++) {
    min1 = fmin(min1, nums1[i]);
    min2 = fmin(min2, nums2[i]);
  }

  return min2 - min1;
}