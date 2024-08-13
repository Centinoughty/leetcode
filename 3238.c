// Find the number of winning players
// EASY

#include <stdio.h>
#include <stdlib.h>

int compare (const void* a, const void* b) {
  int* x = *(int**)a;
  int* y = *(int**)b;
  
  if (x[0] < y[0]) {
    return -1;
  } else if (x[0] > y[0]) {
    return 1;
  } else {
    if (x[1] < y[1]) {
      return -1;
    } else if (x[1] > y[1]) {
      return 1;
    } else {
      return 0;
    }
  }
}

int winningPlayerCount(int n, int** pick, int pickSize, int* pickColSize) {
  qsort(pick, pickSize, sizeof(int*), compare);
  
  int res = 0;
  int curr = pick[0][0];
  int color = pick[0][1];
  int count = 0;
  int maxCount = 0;
  
  for (int i = 0; i < pickSize; i ++) {
    if (curr == pick[i][0]) {
      if (color == pick[i][1]) {
        count ++;
      } else {
        maxCount = fmax(count, maxCount);
        count = 0;
        color = pick[i][1];
        count ++;
      }
    } else {
      maxCount = fmax(count, maxCount);
      count = 0;
      color = pick[i][1];
      
      if (maxCount > curr) {
        res ++;
      }
      
      maxCount = 0;
      curr = pick[i][0];
      count ++;
    }
  }

  maxCount = fmax(maxCount, count);
  if (maxCount > curr) {
    res ++;
  }
  
  return res;
}
