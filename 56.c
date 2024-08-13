// Merge intervals
// MEDIUM

#include <stdio.h>
#include <stdlib.h>

int compare (const void* a, const void* b) {
  return (*(int**)a)[0] - (*(int**)b)[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
  qsort(intervals, intervalsSize, sizeof(int*), compare);
  int pos = 0;
  int i = 1;

  while (i < intervalsSize) {
    if (intervals[pos][1] < intervals[i][0]) {
      pos ++;
      intervals[pos] = intervals[i];
    } else {
      intervals[pos][1] = fmax(intervals[pos][1], intervals[i][1]);
    }

    i ++;
  }

  *returnSize = pos + 1;
  *returnColumnSizes = (int*)malloc((pos + 1) * sizeof(int));
  for (int i = 0; i < pos + 1; i ++) {
    (*returnColumnSizes)[i] = 2;
  }

  return intervals;
}
