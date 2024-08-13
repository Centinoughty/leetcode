// Counting bits
// EASY

#include <stdio.h>
#include <stdlib.h>

int count (int n) {
  int count = 0;
  while (n > 0) {
    if (n & 1) {
      count ++;
    }

    n >>= 1;
  }

  return count;
}

int* countBits(int n, int* returnSize) {
  int* array = (int*)malloc((n + 1) * sizeof(int));
  for (int i = 0; i < n + 1; i ++) {
    array[i] = count(i);
  }

  *returnSize = n + 1;
  return array;
}
