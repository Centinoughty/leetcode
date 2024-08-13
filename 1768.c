// Merge strings alternately
// EASY

#include <stdio.h>
#include <string.h>

char* mergeAlternately(const char* word1, const char* word2) {
  int length1 = strlen(word1);
  int length2 = strlen(word2);
  int n = length1 < length2 ? length1 : length2;
  int totalLength = length1 + length2;
  
  char* merged = (char*)malloc((totalLength + 1) * sizeof(char));
  int j = 0;

  for (int i = 0; i < n; ++i) {
    merged[j++] = word1[i];
    merged[j++] = word2[i];
  }

  for (int i = n; i < length1; ++i) {
    merged[j++] = word1[i];
  }
  for (int i = n; i < length2; ++i) {
    merged[j++] = word2[i];
  }

  merged[j] = '\0';
  return merged;
}
