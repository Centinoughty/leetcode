// Grumpy bookstore owner
// MEDIUM

#include <stdio.h>

int maxSatisfied(int* customers, int customersSize, int* grumpy, int grumpySize, int minutes) {
  int count = 0;
  int maxCount = 0;
  int temp = 0;
  int maxVal = 0;
  int val = 0;

  for (int i = 0; i < customersSize; i ++) {
    if (grumpy[i] == 0) {
      count += customers[i];
    }
  }

  int left = 0;
  int right = 0;

  while (right < minutes && right < customersSize) {
    if (grumpy[right] == 1) {
      temp ++;
      val += customers[right];
    }

    right ++;
  }

  maxVal = val;
  maxCount = temp;

  while (right < customersSize) {
    if (grumpy[right] == 1) {
      val += customers[right];
      temp ++;
    }

    if (grumpy[left] == 1) {
      val -= customers[left];
      temp --;
    }


    maxCount = fmax(maxCount, temp);
    maxVal = fmax(maxVal, val);
    right ++;
    left ++;
  }

  return count + maxVal;
}