// Intersection of two linked lists
// EASY

#include <stdio.h>

struct ListNode {
  int val;
  struct ListNode *next;
};
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
  struct ListNode *ptrA = headA;
  struct ListNode *ptrB = headB;

  while (ptrA != ptrB) {
    ptrA = ptrA ? ptrA->next : headB;
    ptrB = ptrB ? ptrB->next : headA;
  }

  return ptrA;
}