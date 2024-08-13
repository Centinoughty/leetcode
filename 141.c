// Linked list cycle
// EASY

#include <stdio.h>
#include <stdbool.h>

struct ListNode {
  int data;
  struct ListNode* next;
};

bool hasCycle(struct ListNode *head) {
  struct ListNode* slow = head;
  struct ListNode* fast = head;

  while (fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) {
      return true;
    }
  }

  return false;
}