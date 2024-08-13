// Kids with the greatest number of candies
// EASY

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {
  bool* array = (bool*)malloc(candiesSize * sizeof(bool));
  int maxValue = 0;

  for (int i = 0; i < candiesSize; i ++) {
    maxValue = maxValue < candies[i] ? candies[i] : maxValue;
  }

  for (int i = 0; i < candiesSize; i ++) {
    if (candies[i] + extraCandies >= maxValue) {
      array[i] = true;
    } else {
      array[i] = false;
    }
  }

  *returnSize = candiesSize;
  return array;
}