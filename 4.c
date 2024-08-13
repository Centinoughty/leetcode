// Media of two sorted arrays
// HARD

#include <stdio.h>
#include <math.h>
#include <limits.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
  if (nums1Size > nums2Size) {
    return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
  }

  int l = 0, r = nums1Size;
  while (l <= r) {
    int p1 = (l + r) / 2;
    int p2 = (nums1Size + nums2Size + 1) / 2 - p1;

    int maxLeft1 = p1 == 0 ? INT_MIN : nums1[p1 - 1];
    int maxLeft2 = p2 == 0 ? INT_MIN : nums2[p2 - 1];
    int minRight1 = p1 == nums1Size ? INT_MAX : nums1[p1];
    int minRight2 = p2 == nums2Size ? INT_MAX : nums2[p2];

    if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
      return (nums1Size + nums2Size) % 2 ? fmax(maxLeft1, maxLeft2) : (fmax(maxLeft1, maxLeft2) + fmin(minRight1, minRight2)) / 2;
    } else if (maxLeft1 > minRight2) {
      r = p1 - 1;
    } else {
      l = p1 + 1;
    }
  }

  return 0;
}