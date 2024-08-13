// Relative sort array
// EASY

#include <stdio.h>
#include <stdlib.h>

int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize) {
  int maxValue = 0;

  for (int i = 0; i < arr1Size; i ++) {
    maxValue = maxValue < arr1[i] ? arr1[i] : maxValue;
  }

  int* array = (int*)calloc(maxValue + 1, sizeof(int));
  int* result = (int*)malloc((maxValue + 1) * sizeof(int));
  int pos = 0;

  for (int i = 0; i < arr1Size; i ++) {
    array[arr1[i]] ++;
  }

  int j = 0;
  while (j < arr2Size) {
    if (array[arr2[j]] > 0) {
      result[pos ++] = arr2[j];
      array[arr2[j]] --;
    } else {
      j ++;
    }
  }

  int i = 0;
  while (i < maxValue + 1) {
    if (array[i] > 0) {
      array[i] --;
      result[pos ++] = i;
    } else {
      i ++;
    }
  }

  free(array);
  *returnSize = arr1Size;
  return result;
}