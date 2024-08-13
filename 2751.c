// Robot collisions
// HARD

#include <stdio.h>
#include <stdlib.h>

struct Robot {
  int index;
  int pos;
  int health;
  int dir;
};

int compare (const void* a, const void* b) {
  return ((const struct Robot*)a)->pos - ((const struct Robot*)b)->pos;
}

int compareIndex (const void* a, const void* b) {
  return ((const struct Robot*)a)->index - ((const struct Robot*)b)->index;
}

int* survivedRobotsHealths(int* positions, int positionsSize, int* healths, int healthsSize, char * directions, int* returnSize){
  int* result = (int*)malloc(positionsSize * sizeof(int));
  struct Robot* array = (struct Robot*)malloc(positionsSize * sizeof(struct Robot));
  struct Robot* stack = (struct Robot*)malloc(positionsSize * sizeof(struct Robot));
  int pos = 0, top = -1;

  for (int i = 0; i < positionsSize; i ++) {
    array[i].index = i;
    array[i].pos = positions[i];
    array[i].health = healths[i];
    array[i].dir = directions[i];
  }

  qsort(array, positionsSize, sizeof(struct Robot), compare);

  for (int i = 0; i < positionsSize; i ++) {
    if (array[i].dir == 'R') {
      stack[++ top] = array[i];
    } else {
      while (top > - 1 && stack[top].dir == 'R' && array[i].health > 0) {
        if (stack[top].health == array[i].health) {
          top --;
          array[i].health = 0;
        } else if (stack[top].health > array[i].health) {
          stack[top].health --;
          array[i].health = 0;
        } else {
          top --;
          array[i].health --;
        }
      }

      if (array[i].health > 0) {
        stack[++ top] = array[i];
      }
    }
  }

  qsort(stack, top + 1, sizeof(struct Robot), compareIndex);
  for (int i = 0; i <= top; i ++) {
    result[pos ++] = stack[i].health;
  }

  *returnSize = pos;
  return result;
}
