// Find center of star graph
// EASY

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int findCenter(int** edges, int edgesSize, int* edgesColSize) {
  int max = INT_MIN;
  for (int i = 0; i < edgesSize; i ++) {
    max = fmax(max, fmax(edges[i][0], edges[i][1]));
  }

  int res = 0;
  int* array = (int*)calloc(max, sizeof(int));

  for (int i = 0; i < edgesSize; i ++) {
    array[edges[i][0] - 1] ++;
    array[edges[i][1] - 1] ++;
  }

  for (int i = 0; i < max; i++) {
    if (array[i] == max - 1) {
      return i + 1;
    }
  }

  return -1;
}
