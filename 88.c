// Merge sorted array
// EASY

#include <stdio.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
  int i = 0, j = 0;
  int B[m + n];
  int pos = 0;

  while (i < m && j < n) {
    if (nums1[i] <= nums2[j]) {
      B[pos ++] = nums1[i ++];
    } else {
      B[pos ++] = nums2[j ++];
    }
  }

  while (j < n) {
    B[pos ++] = nums2[j ++];
  }

  while (i < m) {
    B[pos ++] = nums1[i ++];
  }

  for (int i = 0; i < m + n; i ++) {
    nums1[i] = B[i];
  }
}