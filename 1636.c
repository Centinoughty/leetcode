// Sort array by increasing frequency
// EASY

#include <stdio.h>
#include <stdlib.h>

struct Element {
  int count;
  int val;
};

int compare (const void* a, const void* b) {
  struct Element* x = (struct Element*)a;
  struct Element* y = (struct Element*)b;
  
  if (x->count > y->count) {
    return 1;
  } else if (x->count < y->count) {
    return -1;
  } else {
    if (x->val > y->val) {
      return -1;
    } else if (x->val < y->val) {
      return 1;
    } else {
      return 0;
    }
  }
}

int* frequencySort(int* nums, int numsSize, int* returnSize) {
  struct Element* array = (struct Element*)malloc(201 * sizeof(struct Element));
  for (int i = 0; i < 201; i ++) {
    array[i].val = i - 100;
    array[i].count = 0;
  }

  for (int i = 0; i < numsSize; i ++) {
    array[nums[i] + 100].count ++;
  }

  qsort(array, 201, sizeof(struct Element), compare);

  int pos = 0;
  int k = 0;
  while (pos < 201 && array[pos].count != 0) {
    pos ++;
  }

  for (int i = pos; i < 201; i ++) {
    while (array[i].count) {
      nums[k ++] = array[i].val;
      array[i].count --;
    }
  }

  *returnSize = numsSize;
  return nums;
}
