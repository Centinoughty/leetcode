// Asteroid collision
// MEDIUM

#include <stdio.h>
#include <stdlib.h>

int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize) {
  int* array = (int*)malloc(asteroidsSize * sizeof(int));
  int top = -1;
  
  for (int i = 0; i < asteroidsSize; i ++) {
    if (asteroids[i] > 0) {
      array[++ top] = asteroids[i];
    } else {
      while (top >= 0 && array[top] > 0 && array[top] < -asteroids[i]) {
        top --;
      }

      if (top < 0 || array[top] < 0) {
        array[++ top] = asteroids[i];
      } else if (array[top] == -asteroids[i]) {
        top --;
      }
    }
  }

  *returnSize = top + 1;
  return array;
}