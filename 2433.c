// Find the original array of prefix XOR
// MEDIUM

#include <stdio.h>
#include <stdlib.h>

int* findArray(int* pref, int prefSize, int* returnSize) {
  int* array = (int*)malloc(prefSize * sizeof(int));
  array[0] = pref[0];
  for (int i = 1; i < prefSize; i ++) {
    array[i] = pref[i] ^ pref[i - 1];
  }

  *returnSize = prefSize;
  return array;
}