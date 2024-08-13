// Minimum number of moves to seat everyone
// EASY

#include <stdio.h>

int compare (const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int abs (int n) {
    return n < 0 ? -n : n;
}

int minMovesToSeat(int* seats, int seatsSize, int* students, int studentsSize) {
  int count = 0;

  qsort(seats, seatsSize, sizeof(int), compare);
  qsort(students, studentsSize, sizeof(int), compare);

  for (int i = 0; i < seatsSize; i ++) {
    count += abs(seats[i] - students[i]);
  }

  return count;
}