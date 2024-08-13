// Removing stars from a string
// MEDIUM

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* removeStars(char* s) {
  int length = strlen(s);
  char* string = (char*)malloc((length + 1) * sizeof(char));
  int top = -1;

  for (int i = 0; i < length; i ++) {
    if (s[i] != '*') {
      string[++ top] = s[i];
    } else {
      top = top >= 0 ? top - 1 : -1;
    }
  }

  string[++ top] = '\0';
  return string;
}