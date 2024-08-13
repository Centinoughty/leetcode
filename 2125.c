// Number of laser beams in a bank
// MEDIUM

#include <stdio.h>
#include <stdlib.h>

int numberOfBeams(char** bank, int bankSize) {
  int* array = (int*)calloc(bankSize, sizeof(int));
  int pos = 0;
  int result = 0;
  int prev = 0;
  
  for (int i = 0; i < bankSize; i ++) {
    int j = 0;
    int count = 0;
    while (bank[i][j] != '\0') {
      if (bank[i][j] == '1') {
        count ++;
      }

      j ++;
    }

    array[pos ++] = count;
  }

  for (int i = 0; i < bankSize; i ++) {
    if (array[i] > 0) {
      result += array[i] * prev;
      prev = array[i];
    }
  }

  return result;
}
