// Find the student that will replace the chalk
// MEDIUM

#include <stdio.h>

int chalkReplacer(int* chalk, int chalkSize, int k) {
  long int sum = 0;
  for (int i = 0; i < chalkSize; i ++) {
    sum += chalk[i];
  }
  k %= sum;

  if (k == 0) {
    return 0;
  }

  for (int i = 0; i < chalkSize; i ++) {
    k -= chalk[i];
    if (k < 0) {
      return i;
    }
  }

  return 0;
}
