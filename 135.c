// Candy
// HARD

#include <stdio.h>
#include <stdlib.h>

int candy(int* ratings, int ratingsSize) {
  int count = 0;

  int* candies = (int*)malloc(ratingsSize * sizeof(int));
  for (int i = 0; i < ratingsSize; i ++) {
    candies[i] = 1;
  }

  for (int i = 1; i < ratingsSize; i ++) {
    if (ratings[i] > ratings[i - 1] && candies[i] <= candies[i - 1]) {
      candies[i] = candies[i - 1] + 1;
    }
  }

  for (int i = ratingsSize - 2; i >= 0; i --) {
    if (ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1]) {
      candies[i] = candies[i + 1] + 1;
    }
  }

  for (int i = 0; i < ratingsSize; i ++) {
    count += candies[i];
  }

  free(candies);
  return count;
}