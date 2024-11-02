// Circular sentence
// EASY

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isCircularSentence(char* sentence) {
  int length = strlen(sentence);
  if (sentence[0] != sentence[length - 1]) {
    return false;
  }

  for (int i = 1; sentence[i] && sentence[i + 1]; i ++) {
    if (sentence[i] == ' ') {
      if (sentence[i - 1] != sentence[i + 1]) {
        return false;
      }
    }
  }

  return true;
}
