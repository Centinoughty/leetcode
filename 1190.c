// Reverse substrings between each pair of parentheses
// MEDIUM

#include <stdio.h>
#include <stdlib.h>

void reverse (char* s, int l, int r) {
  while (l < r) {
    char temp = s[l];
    s[l] = s[r];
    s[r] = temp;
    l ++;
    r --;
  }
}

char* reverseParentheses(char* s) {
  int length = strlen(s);
  int* array = (int*)malloc((length + 1) * sizeof(int));
  char* string = (char*)malloc((length + 2) * sizeof(char));
  int top = -1;
  int pos = 0;

  for (int i = 0; s[i] != '\0'; i ++) {
    if (s[i] == '(') {
      array[++top] = pos;
    } else if (s[i] == ')') {
      int temp = array[top];
      top --;
      reverse(string, temp, pos - 1);
    } else {
      string[pos ++] = s[i];
    }
  }

  string[pos] = '\0';
  return string;
}
