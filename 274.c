// H-index
// MEDIUM

#include <stdio.h>
#include <stdlib.h>

int compare (const void* a, const void* b) {
  return *(int*) a - *(int*)b;
}

int hIndex(int* citations, int citationsSize) {
  qsort(citations, citationsSize, sizeof(int), compare);

  for (int i = 0; i < citationsSize; i ++) {
    if (citations[i] >= citationsSize - i) {
      return citationsSize - i;
    }
  }

  return 0;
}