// Minimum number of days to make m boquets
// MEDIUM

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

bool isPossible (int* nums, int numsSize, int m, int k, int days) {
  int count = 0;
  int current = 0;
  for (int i = 0; i < numsSize; i ++) {
    if (nums[i] <= days) {
      current ++;
      if (current == k) {
        count ++;
        current = 0;
      }
    } else {
      current = 0;
    }
  }

  return count >= m;
}

int minDays(int* bloomDay, int bloomDaySize, int m, int k) {
  int left = INT_MAX;
  int right = INT_MIN;

  for (int i = 0; i < bloomDaySize; i ++) {
    left = fmin(left, bloomDay[i]);
    right = fmax(right, bloomDay[i]);
  }

  while (left < right) {
    int mid = (left + right) / 2;
    if (isPossible(bloomDay, bloomDaySize, m, k, mid)) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }

  return isPossible(bloomDay, bloomDaySize, m, k, left) ? left : -1;
}