// Minimum cost for cutting cake I
// MEDIUM

#include <stdio.h>
#include <stdlib.h>

int compare (const void* a, const void* b) {
  return *(int*)b - *(int*)a;
}

long long minimumCost(int m, int n, int* horizontalCut, int horizontalCutSize, int* verticalCut, int verticalCutSize) {
  qsort(horizontalCut, horizontalCutSize, sizeof(int), compare);
  qsort(verticalCut, verticalCutSize, sizeof(int), compare);
  
  int h = 1, v = 1;
  long long result = 0;
  int i = 0, j = 0;
  
  while (i < horizontalCutSize && j < verticalCutSize) {
    if (horizontalCut[i] >= verticalCut[j]) {
      result += (long long)(horizontalCut[i] * v);
      h ++;
      i ++;
    } else {
      result += (long long)(verticalCut[j] * h);
      v ++;
      j ++;
    }
  }
  
  while (i < horizontalCutSize) {
    result += (long long)(horizontalCut[i] * v);
    h ++;
    i ++;
  }
  
  while (j < verticalCutSize) {
    result += (long long)(verticalCut[j] * h);
    v ++;
    j ++;
  }
  
  return result;
}
