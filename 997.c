// Find the town judge
// EASY

#include <stdio.h>
#include <stdlib.h>

int findJudge(int n, int** trust, int trustSize, int* trustColSize) {
  int* array = (int*)calloc(n, sizeof(int));
  for (int i = 0; i < trustSize; i ++) {
    array[trust[i][0] - 1] --;
    array[trust[i][1] - 1] ++;
  }

  for (int i = 0; i < n; i ++) {
    if (array[i] == n - 1) {
      return i + 1;
    }
  }

  return -1;
}
