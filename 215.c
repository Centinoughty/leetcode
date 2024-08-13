// Kth largest element in an array
// MEDIUM

#include <stdio.h>

void maxHeapify (int* nums, int numsSize, int i) {
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  int max = i;

  if (left < numsSize && nums[left] > nums[max]) {
    max = left;
  }

  if (right < numsSize && nums[right] > nums[max]) {
    max = right;
  }

  if (max != i) {
    int temp = nums[i];
    nums[i] = nums[max];
    nums[max] = temp;
    maxHeapify(nums, numsSize, max);
  }
}

void buildHeap (int* nums, int numsSize) {
  for (int i = numsSize / 2 - 1; i >= 0; i --) {
    maxHeapify(nums, numsSize, i);
  }
}

int extractMax (int* nums, int* numsSize) {
  int temp = nums[0];
  nums[0] = nums[-- (*numsSize)];
  maxHeapify(nums, *numsSize, 0);
  return temp;
}

int findKthLargest(int* nums, int numsSize, int k) {
  buildHeap(nums, numsSize);

  int res = -1;
  for (int i = 0; i < k; i ++) {
    res = extractMax(nums, &numsSize);
  }

  return res;
}
