// Number of steps to reduce a number in binary representation to one
// MEDIUM


#include <stdio.h>
#include <string.h>

int numSteps(char* s) {
  int count = 0;
  int length = strlen(s);

  while (s[length - 1] == '0') {
    s[length - 1] = '\0';
    length --;
    count ++;
  }

  if (length == 1) {
    return count;
  }

  count ++;
  for (int i = 0; i < length; i ++) {
    count += s[i] == '0' ? 2 : 1;
  }

  return count;
}