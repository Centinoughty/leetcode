// Reverse bits
// EASY

#include <stdio.h>
#include <stdint.h>

uint32_t reverseBits(uint32_t n) {
  uint32_t x = 0;
  for (int i = 0; i < 32; i ++) {
    x <<= 1;
    x |= (n & 1);
    n >>= 1;
  }

  return x;
}