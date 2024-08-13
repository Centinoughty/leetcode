// Minimum suffix flips
// MEDIUM

#include <stdio.h>

int minFlips(char* target) {
  int res = 0;
  int temp = 0;

  for (int i = 0; target[i] != '\0'; i ++) {
    if (target[i] - '0' != temp) {
      temp = target[i] - '0';
      res ++;
    }
  }

  return res;
}
