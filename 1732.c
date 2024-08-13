// Find the highest altitude
// EASY

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int largestAltitude(int* gain, int gainSize) {
  int* array = (int*)calloc(gainSize + 1, sizeof(int));
  int max = INT_MIN;
  
  for (int i = 1; i < gainSize + 1; i ++) {
    array[i] = array[i - 1] + gain[i - 1];
  }

  for (int i = 0; i < gainSize + 1; i ++) {
    max = max < array[i] ? array[i] : max;
  }

  free(array);
  return max;
}