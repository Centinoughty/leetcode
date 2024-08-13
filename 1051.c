// Height checker
// EASY

#include <stdio.h>
#include <stdlib.h>

void countSort (int A[], int n, int pos) {
  int count[10];
  int b[n];
  for (int i = 0; i < 10; i ++) {
    count[i] = 0;
  }

  for (int i = 0; i < n; i ++) {
    count[(A[i] / pos) % 10] ++;
  }

  for (int i = 1; i < 10; i ++) {
    count[i] += count[i - 1];
  }

  for (int i = n - 1; i >= 0; i --) {
    b[--count[(A[i] / pos) % 10]] = A[i];
  }

  for (int i = 0; i < n; i ++) {
    A[i] = b[i];
  }
}


void radixSort (int A[], int n) {
  int k = 0, max = A[0];
  for (int i = 0; i < n; i ++) {
    if (A[i] > max) {
      max =A[i];
    }
  }

  int temp = max;
  while (temp != 0) {
    k ++;
    temp /= 10;
  }

  for (int i = 1; max / i > 0; i *= 10) {
    countSort(A, n, i);
  }
}

int heightChecker(int* heights, int heightsSize) {
  int* array = (int*)malloc(100 * sizeof(int));
  int count = 0;

  for (int i = 0; i < heightsSize; i ++) {
    array[i] = heights[i];
  }

  radixSort(array, heightsSize);

  for (int i = 0; i < heightsSize; i ++) {
    if (array[i] != heights[i]) {
      count ++;
    }
  }

  return count;
}