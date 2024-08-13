// Sort the people
// EASY

#include <stdio.h>
#include <stdlib.h>

void swap(char** str1, char** str2) {
  char* temp= *str1;
  *str1 = *str2;
  *str2 = temp;
}

char** sortPeople(char** names, int namesSize, int* heights, int heightsSize, int* returnSize) {
  for (int i = 0; i < heightsSize - 1; i ++) {
    int maximum = i;
    for (int j = i + 1; j < heightsSize; j ++) {
      if (heights[j] > heights[maximum]) {
        maximum = j;
      }
    }

    swap(&names[i], &names[maximum]);

    int temp = heights[i];
    heights[i] = heights[maximum];
    heights[maximum] = temp;
  }

  *returnSize = namesSize;
  return names;
}
