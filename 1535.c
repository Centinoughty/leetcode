// Find the winner of an array game
// MEDIUM

#include <stdio.h>

int getWinner(int* arr, int arrSize, int k) {
  int winCount = 0;
  int index = 0;

  for (int i = 1; i < arrSize && winCount < k; i ++) {
    if (arr[i] > arr[index]) {
      index = i;
      winCount = 1;
    } else {
      winCount ++;
    }
  }

  return arr[index];
}