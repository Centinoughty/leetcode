// Excel sheet column number
// EASY

#include <stdio.h>

int titleToNumber(char* columnTitle) {
  int result = 0;

  for (int i = 0; columnTitle[i] != '\0'; i ++) {
    result *= 26;
    result += (columnTitle[i] - 'A' + 1);
  }

  return result;
}