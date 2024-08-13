// Linked list cycle II
// MEDIUM

#include <stdio.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *detectCycle(struct ListNode *head) {
  if (head == NULL || head->next == NULL) {
    return NULL;
  }

  struct ListNode* slow = head;
  struct ListNode* fast = head;

  while (fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast) {
      struct ListNode* temp = head;
      while (temp != slow) {
        slow = slow->next;
        temp = temp->next;
      }

      return temp;
    }
  }

  return NULL;
}
