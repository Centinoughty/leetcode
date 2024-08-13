// Append charecters to string to make subsequence
// MEDIUM

#include <stdio.h>
#include <string.h>

int appendCharacters(char* s, char* t) {
  int i = 0, j = 0;
  int l1 = strlen(s), l2 = strlen(t);
  while (i < l1) {
    if (s[i] == t[j]) {
      j ++;
    }

    i ++;
  }

  return l2 - j;
}