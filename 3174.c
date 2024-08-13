// Clear digits
// EASY

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* clearDigits(char* s) {
  int length = strlen(s);
  for (int i = 0; i < length; i ++) {
    if (isdigit(s[i])) {
      for (int j = i - 1; j >= 0; j --) {
          if (isalpha(s[j])) {
            s[i] = '.';
            s[j] = '.';
            break;
          }
      }
    }
  }
  
  char* string = (char*)malloc((length + 1) * sizeof(char));
  int pos = 0;
  for (int i = 0; i < length; i ++) {
    if (s[i] != '.') {
      string[pos ++] = s[i];
    }
  }
  
  string[pos] = '\0';
  return string;
}