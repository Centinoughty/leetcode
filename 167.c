// Two sum II - input array is sorted
// MEDIUM

#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
  int* array = (int*)malloc(2 * sizeof(int));
  *returnSize = 2;
  int left = 0, right = numbersSize - 1;
  while (left < right) {
    int temp = numbers[left] + numbers[right];
    if (temp == target) {
      array[0] = left + 1;
      array[1] = right + 1;
      break;
    } else if (temp > target) {
      right --;
    } else {
      left ++;
    }
  }

  return array;
}