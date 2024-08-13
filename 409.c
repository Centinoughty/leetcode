// Longest palindrome
// EASY

#include <stdio.h>
#include <string.h>

int longestPalindrome(char* s) {
  int* count = (int*)calloc(58, sizeof(int));
  int length = strlen(s);
  int result = 0;
  int odd = 0;

  for (int i = 0; i < length; i ++) {
    count[s[i] - 'A'] ++;
  }

  for (int i = 0; i < 58; i ++) {
    result += count[i] % 2 ? count[i] - 1 : count[i];
    odd = count[i] % 2 ? odd + 1 : odd;
  }

  free(count);

  return odd > 0 ? result + 1 : result;
}