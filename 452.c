// Minimum number of arrows to burst balloons
// MEDIUM

#include <stdio.h>
#include <stdlib.h>

int compare (const void* a, const void* b) {
  return (*(int**)a)[1] < (*(int**)b)[1] ? -1 : 1;
}

int findMinArrowShots(int** points, int pointsSize, int* pointsColSize) {
  qsort(points, pointsSize, sizeof(int*), compare);
  int count = 1;
  int start = points[0][1];

  for (int i = 1; i < pointsSize; i ++) {
    if (start < points[i][0]) {
      start = points[i][1];
      count++;
    }
  }

  return count;
}
