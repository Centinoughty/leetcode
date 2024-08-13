// Lexicographically smallest string after a swap
// EASY

#include <stdio.h>

char* getSmallestString(char* s) {
  for (int i = 1; s[i] != '\0'; i ++) {
    if (s[i] < s[i - 1]) {
      if (s[i] % 2 == s[i - 1] % 2) {
        char temp = s[i];
        s[i] = s[i - 1];
        s[i - 1] = temp;
        break;
      }
    }
  }
  
  return s;
}
