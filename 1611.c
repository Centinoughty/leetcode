// Minimum one bit operations to make integers zero
// HARD

#include <stdio.h>

int minimumOneBitOperations(int n) {
  if (n == 0) {
    return 0;
  }

  int x = 1;
  while (x * 2 <= n) {
    x <<= 1;
  }

  return minimumOneBitOperations(n ^ (x | x >> 1)) + x;
}