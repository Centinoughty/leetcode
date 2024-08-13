// Get equal substrings within budget
// MEDIUM

#include <stdio.h>
#include <string.h>
#include <math.h>

int abs (int x) {
  return x < 0 ? -x : x;
}

int equalSubstring(char* s, char* t, int maxCost) {
  int start = 0;
  int cost = 0;
  int length = strlen(s);
  int maxLength = 0;

  for (int i = 0; i < length; i ++) {
    cost += abs(s[i] - t[i]);
    while (cost > maxCost) {
      cost -= abs(s[start] - t[start]);
      start ++;
    }

    maxLength = fmax(maxLength, i - start + 1);
  }

  return maxLength;
}