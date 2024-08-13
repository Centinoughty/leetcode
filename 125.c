// Valid palindrome
// EASY

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

bool isPalindrome(char* s) {
  int left = 0;
  int right = 0;
  while (s[right ++]);
  right --;

  while (left <= right) {
    if (!isalnum(s[left])) {
      left ++;
    } else if (!isalnum(s[right])) {
      right --;
    } else if (tolower(s[left]) == tolower(s[right])) {
      left ++;
      right --;
    } else {
      return false;
    }
  }

  return true;
}