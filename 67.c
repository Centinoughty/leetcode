// Add binary
// EASY

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* addBinary(char* a, char* b) {
  int lengthA = strlen(a);
  int lengthB = strlen(b);

  if (lengthB > lengthA) {
    return addBinary(b, a);
  }

  int maxLength = lengthA + 2;
  char* result = (char*)malloc(maxLength * sizeof(char));
  int carry = 0;
  int pos = maxLength - 2;

  int i = lengthA - 1;
  int j = lengthB - 1;

  while (i >= 0 || j >= 0 || carry > 0) {
    int temp = carry;
    if (i >= 0 && a[i --] == '1') {
      temp ++;
    }

    if (j >= 0 && b[j --] == '1') {
      temp ++;
    }

    result[pos --] = temp % 2 ? '1' : '0';
    carry = temp / 2;
  }

  result[maxLength - 1] = '\0';
  if (result[0] != '1' && result[0] != '0') {
    for (int i = 0; i < maxLength - 1; i ++) {
      result[i] = result[i + 1];
    }
  }

  return result;
}