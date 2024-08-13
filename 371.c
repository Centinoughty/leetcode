// Sum of two integers
// MEDIUM

#include <stdio.h>

int getSum(int a, int b) {
  while (b != 0) {
    int carry = a & b;
    a ^= b;
    b = (unsigned int)carry << 1;
  }

  return a;
}