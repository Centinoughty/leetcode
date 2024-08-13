// Number of digit one
// HARD

#include <stdio.h>

int countDigitOne(int n) {
  int res = 0;
  for (long i = 1; i <= n; i *= 10) {
    long quotient = n / i, remainder = n % i;
    res += (quotient + 8) / 10 * i;
    if (quotient % 10 == 1) {
      res += remainder + 1;
    }
  }

  return res;
}
