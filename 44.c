// Wildcard matching
// HARD

#include <stdio.h>
#include <stdbool.h>

bool isMatch(char* s, char* p) {
  int i = 0, j = 0;
  int start = -1, ind = 0;

  while (s[i] != '\0') {
    if (p[j] == '?' || s[i] == p[j]) {
      i ++;
      j ++;
    } else if (p[j] == '*') {
      start = j;
      ind = i;
      j ++;
    } else if (start != -1) {
      j = start + 1;
      ind ++;
      i = ind;
    } else {
      return false;
    }
  }

  while (p[j] == '*') {
    j ++;
  }

  return p[j] == '\0';
}