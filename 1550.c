// Three consecutive odds
// EASY

#include <stdio.h>
#include <stdbool.h>

bool threeConsecutiveOdds(int* arr, int arrSize) {
  if (arrSize < 3) {
    return false;
  }

  int oddCount = 0;
  int i = 0, j = 0;
  for (j = 0; j < 3; j ++) {
    if (arr[j] % 2) {
      oddCount ++;
    }
  }

  while (j < arrSize) {
    if (arr[i] % 2) {
      oddCount -= oddCount == 0 ? 0 : 1;
    }

    if (arr[j] % 2) {
      oddCount ++;
    }

    if (oddCount == 3) {
      return true;
    }

    i ++;
    j ++;
  }

  return oddCount != 3 ? false : true;
}