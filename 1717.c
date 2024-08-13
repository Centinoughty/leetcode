// Maximum score from removing substrings
// MEDIUM

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maximumGain(char* s, int x, int y) {
  int result = 0;

  int len = strlen(s);
  char* str1 = (char*)malloc((len + 1) * sizeof(char));
  char* str2 = (char*)malloc((len + 1) * sizeof(char));
  int top1 = -1, top2 = -1;
  int flag = 1;

  if (x > y) {
      flag = 0;
  }

  for (int i = 0; s[i] != '\0'; i ++) {
    if (flag) {
      if (s[i] == 'a' && top1 > -1 && str1[top1] == 'b') {
        top1 --;
        result += y;
      } else {
        str1[++ top1] = s[i];
      }
    } else {
      if (s[i] == 'b' && top1 > -1 && str1[top1] == 'a') {
        top1 --;
        result += x;
      } else {
        str1[++ top1] = s[i];
      }
    }
  }
  str1[++ top1] = '\0';

  for (int i = 0; str1[i] != '\0'; i ++) {
    if (flag) {
      if (str1[i] == 'b' && top2 > -1 && str2[top2] == 'a') {
          top2 --;
          result += x;
      } else {
          str2[++ top2] = str1[i];
      }
    } else {
      if (str1[i] == 'a' && top2 > -1 && str2[top2] == 'b') {
        top2 --;
        result += y;
      } else {
        str2[++ top2] = str1[i];
      }
    }
  }

  return result;
}
