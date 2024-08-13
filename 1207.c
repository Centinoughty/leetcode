// Unique number of occurrences
// EASY

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int compare (const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

bool uniqueOccurrences(int* arr, int arrSize) {
  int* array = (int*)calloc(2001, sizeof(int));

  for (int i = 0; i < arrSize; i ++) {
    array[arr[i] + 1000] ++;
  }

  qsort(array, 2001, sizeof(int), compare);

  int i = 0;
  while (i < 2001 && array[i] == 0) {
    i ++;
  }

  for (int j = i + 1; j < 2001; j ++) {
    if (array[j] == array[j - 1]) {
      return false;
    }
  }

  free(array);
  return true;
}