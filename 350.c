// Intersection of two arrays II
// EASY

#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
  int min = nums2Size < nums1Size ? nums2Size : nums1Size;
  int* result = (int*)malloc(min * sizeof(int));
  int pos = 0;

  if (nums1Size < nums2Size) {
    return intersect(nums2, nums2Size, nums1, nums1Size, returnSize);
  } else {
    int* array = (int*)calloc(1001, sizeof(int));

    for (int i = 0; i < nums1Size; i ++) {
      array[nums1[i]] ++;
    }

    for (int i = 0; i < nums2Size; i ++) {
      if (array[nums2[i]] > 0) {
        array[nums2[i]] --;
        result[pos ++] = nums2[i];
      }
    }

    free(array);
  }

  *returnSize = pos;
  return result;
}