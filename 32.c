// Longest valid parentheses
// HARD

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int longestValidParentheses(char* s) {
  int length = strlen(s);
  int maxLength = 0;
  int current = 0;
  int* array = (int*)malloc(length * sizeof(int));
  int top = -1;

  for (int i = 0; i < length; i ++) {
    if (s[i] == '(') {
      array[++ top] = i;
    } else {
      if (top >= 0 && s[array[top]] == '(') {
        top --;
        int start = top == -1 ? -1 : array[top];
        int current = i - start;
        maxLength = fmax(maxLength, current);
      } else {
        array[++ top] = i;
      }
    }
  }

  free(array);
  return maxLength;
}