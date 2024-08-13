// Find the minimum and maximum number of nodes between critical points
// MEDIUM

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

int lengthNode (struct ListNode* head) {
  struct ListNode* temp = head;
  int length = 0;
  while (temp) {
    temp = temp->next;
    length ++;
  }

  return length;
}

int* nodesBetweenCriticalPoints(struct ListNode* head, int* returnSize) {
  int* array = (int*)malloc(2 * sizeof(int));
  int length = lengthNode(head);
  int* new = (int*)malloc(length * sizeof(int));
  int pos = 0;

  struct ListNode* prev = NULL;
  struct ListNode* temp = head;
  struct ListNode* next = NULL;
  int curr = 0;

  prev = temp;
  temp = temp->next;
  curr ++;
  next = temp->next;

  while (next) {
    if (prev->val > temp->val && temp->val < next->val) {
      new[pos ++] = curr;
    } else if (prev->val < temp->val && temp->val > next->val) {
      new[pos ++] = curr;
    }

    prev = temp;
    temp = temp->next;
    next = temp->next;
    curr ++;
  }

  if (pos > 1) {
    int min = INT_MAX;
    for (int i = 1; i < pos; i ++) {
      min = fmin(min, new[i] - new[i - 1]);
    }
    array[0] = min;
    array[1] = new[pos - 1] - new[0];
  } else {
    array[0] = array[1] = -1;
  }

  *returnSize = 2;
  return array;
}
