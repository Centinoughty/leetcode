// Is subsequence
// EASY

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isSubsequence(char* s, char* t) {
  int lengthS = strlen(s);
  int lengthT = strlen(t);

  if (lengthS > lengthT) {
    return false;
  }

  int pos = 0;
  for (int i = 0; i < lengthT && s[pos]; i ++) {
    if (s[pos] == t[i]) {
      pos ++;
    }
  }

  if (pos != lengthS) {
    return false;
  } else {
    return true;
  }
}