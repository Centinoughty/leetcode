// Delete the middle node of a linked list
// MEDIUM

#include <stdio.h>


struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode* deleteMiddle(struct ListNode* head) {
  struct ListNode* temp = head;
  int count = 0;
  while (temp != NULL) {
    temp = temp->next;
    count ++;
  }

  count /= 2;

  if (count == 0) {
    return NULL;
  }

  temp = head;
  while (temp != NULL && count > 1) {
    temp = temp->next;
    count --;
  }

  temp->next = temp->next->next;
  return head;
}
