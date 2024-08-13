// Reverse nodes in k-groups
// HARD

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode* reverse (struct ListNode* head, struct ListNode* tail) {
  struct ListNode* prev = NULL;
  struct ListNode* curr = head;

  while (curr != tail) {
    struct ListNode* next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }

  return prev;
}

struct ListNode* reverseKGroup (struct ListNode* head, int k) {
  struct ListNode* tail = head;

  for (int i = 0; i < k; i ++) {
    if (tail == NULL) {
      return head;
    }

    tail = tail->next;
  }

  struct ListNode* temp = reverse(head, tail);
  head->next = reverseKGroup(tail, k);
  return temp;
}