// Most profit assigning work
// MEDIUM

#include <stdio.h>
#include <stdlib.h>

struct Job {
  int difficulty;
  int profit;
};

int compareStruct (const void* a, const void* b) {
  return ((struct Job*)a)->difficulty - ((struct Job*)b)->difficulty;
}

int compare (const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int maxProfitAssignment(int* difficulty, int difficultySize, int* profit, int profitSize, int* worker, int workerSize) {
  struct Job* array = (struct Job*)malloc(difficultySize * sizeof(struct Job));

  for (int i = 0; i < difficultySize; i ++) {
    array[i].difficulty = difficulty[i];
    array[i].profit = profit[i];
  }

  qsort(array, difficultySize, sizeof(struct Job), compareStruct);
  qsort(worker, workerSize, sizeof(int), compare);

  int maxProfit = 0;
  int current = 0;
  int j = 0;

  for (int i = 0; i < workerSize; i ++) {
    for (; j < difficultySize && worker[i] >= array[j].difficulty; j ++) {
      current = fmax(current, array[j].profit);
    }

    maxProfit += current;
  }

  return maxProfit;
}
