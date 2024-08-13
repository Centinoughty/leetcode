// Minimum add to make parentheses valid
// MEDIUM

#include <stdio.h>
#include <string.h>

int minAddToMakeValid(char* s) {
  int length = strlen(s);
  char* arr = (char*)malloc(length * sizeof(char));
  int top = -1;
  int count = 0;

  for (int i = 0; i < length; i ++) {
    if (s[i] == '(') {
      arr[++ top] = '(';
      count ++;
    } else {
      if (top == -1 || arr[top] != '(') {
        count ++;
      } else {
        top --;
        count --;
      }
    }
  }

  return count;
}
