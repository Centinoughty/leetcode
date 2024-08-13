// Magnetic force between two balls
// MEDIUM

#include <stdio.h>
#include <stdlib.h>

int compare (const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int count (int* nums, int numsSize, int force) {
  int result = 0;
  int prev = -force;
  for (int i = 0; i < numsSize; i ++) {
    if (nums[i] - prev >= force) {
      result ++;
      prev = nums[i];
    }
  }

  return result;
}

int maxDistance(int* position, int positionSize, int m) {
  qsort(position, positionSize, sizeof(int), compare);

  int left = 1;
  int right = position[positionSize - 1] - position[0];

  while (left < right) {
    int mid = right - (right - left) / 2;
    if (count(position, positionSize, mid) >= m) {
      left = mid;
    } else {
      right = mid - 1;
    }
  }

  return left;
}