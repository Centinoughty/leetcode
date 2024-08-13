// Make two arrays equal by reversing subarrays
// EASY

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool canBeEqual(int* target, int targetSize, int* arr, int arrSize) {
  int* array1 = (int*)calloc(1001, sizeof(int));
  int* array2 = (int*)calloc(1001, sizeof(int));

  for (int i = 0; i < targetSize; i ++) {
    array1[target[i]] ++;
  }

  for (int i = 0; i < arrSize; i ++) {
    array2[arr[i]] ++;
  }

  for (int i = 0; i < 1001; i ++) {
    if (array1[i] != array2[i]) {
      return false;
    }
  }

  return true;
}
