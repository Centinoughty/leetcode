// Merge nodes in between zeroes
// MEDIUM

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode* createNode(int val) {
  struct ListNode* temp = malloc(sizeof(struct ListNode));
  temp->val = val;
  temp->next = NULL;
  return temp;
}

struct ListNode* mergeNodes(struct ListNode* head) {
  struct ListNode* result = NULL;
  struct ListNode* temp = result;
  int sum = 0;

  while (head) {
    if (head->val == 0) {
      if (sum != 0) {
        if (result == NULL) {
          result = createNode(sum);
          temp = result;
        } else {
          temp->next = createNode(sum);
          temp = temp->next;
        }
        sum = 0;
      }
    } else {
      sum += head->val;
    }

    head = head->next;
  }

  return result;
}