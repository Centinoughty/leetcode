// Maximum total importance of roads
// MEDIUM

#include <stdio.h>
#include <stdlib.h>

struct value {
  int val;
  int index;
};

int compareVal (const void* a, const void* b) {
  return ((struct value*)a)->val - ((struct value*)b)->val;
}

int compareIndex (const void* a, const void* b) {
  return ((struct value*)a)->index - ((struct value*)b)->index;
}

long long maximumImportance(int n, int** roads, int roadsSize, int* roadsColSize) {
  struct value* array = (struct value*)calloc(n, sizeof(struct value));
  long long result = 0;

  for (int i = 0; i < n; i ++) {
    array[i].index = i;
  }

  for (int i = 0; i < roadsSize; i ++) {
    array[roads[i][0]].val ++;
    array[roads[i][1]].val ++;
  }

  qsort(array, n, sizeof(struct value), compareVal);

  array[0].val = 1;
  for (int i = 1; i < n; i ++) {
    array[i].val = array[i - 1].val + 1;
  }

  qsort(array, n, sizeof(struct value), compareIndex);

  for (int i = 0; i < roadsSize; i ++) {
    result += array[roads[i][0]].val + array[roads[i][1]].val;
  }

  free(array);
  return result;
}
