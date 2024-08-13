// Reducing dishes
// HARD

#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
  return *(int*)b - *(int*)a;
}

int maxSatisfaction(int* satisfaction, int satisfactionSize) {
  int current = 0;
  int result = 0;

  qsort(satisfaction, satisfactionSize, sizeof(int), compare);

  for (int i = 0; i < satisfactionSize; i ++) {
    current += satisfaction[i];
    if (current <= 0) {
      return result;
    }
    result += current;
  }

  return result;
}