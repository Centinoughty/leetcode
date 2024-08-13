// Count pairs that form a complete day II
// MEDIUM

#include <stdio.h>
#include <stdlib.h>

long long countCompleteDayPairs(int* hours, int hoursSize) {
  int* array = (int*)calloc(24, sizeof(int));
  long long int count = 0;
  
  for (int i = 0; i < hoursSize; i ++) {
    array[hours[i] % 24] ++;
  }
  
  for (int i = 0; i < 24; i ++) {
    if (array[i] > 0) {
      if (i != 0 && i != 12) {
        count += (long long)array[i] * array[24 - i];
        array[i] = 0;
      } else {
        count += (long long)array[i] * (array[i] - 1) / 2;
      }
    }
  }
  
  return count;
}
