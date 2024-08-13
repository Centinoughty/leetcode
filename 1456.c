// Maximum number of vowels in a substring of given length
// MEDIUM

#include <stdio.h>
#include <string.h>

int isVowel (char c) {
  return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int maxVowels(char* s, int k) {
  int maxCount = 0;
  int current = 0;
  int length = strlen(s);
  for (int i = 0; i < k; i ++) {
    if (isVowel(s[i])) {
      current ++;
    }
  }

  maxCount = current;
  for (int i = k; i < length; i ++) {
    if (isVowel(s[i])) {
      current ++;
    }

    if (isVowel(s[i - k])) {
      current --;
    }

    maxCount = maxCount < current ? current : maxCount;
  }

  return maxCount;
}