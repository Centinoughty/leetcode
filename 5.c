// Longest palindromic substring
// MEDIUM

#include <stdio.h>
#include <string.h>

char* longestPalindrome(char* s) {
  int length = strlen(s);
  int l = 0;
  char* longest = "";
  while (l < length) {
    for (int i = length - 1; i >= l; i --) {
      int left = l;
      int right = i;
      while (left < right && s[left] == s[right]) {
        left ++;
        right --;
      }

      if (left >= right) {
        int len = i - l + 1;
        if (len > strlen(longest)) {
          longest = strndup(s + l, len);
        }

        break;
      }
    }

    l ++;
  }

  return longest;
}