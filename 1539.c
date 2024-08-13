// Kth missing positive number
// EASY

#include <stdio.h>

int findKthPositive(int* arr, int arrSize, int k) {
  int i = 1, pos = 0;
  int count = 0, res = 0;

  while (count < k) {
    if (pos < arrSize && i == arr[pos]) {
      pos ++;
    } else {
      res = i;
      count ++;
    }

    i ++;
  }

  return res;
}