// Insert greatest common divisors in linked list
// MEDIUM

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

int gcd (int a, int b) {
  if (b == 0) {
    return a;
  } else if (a > b) {
    return gcd(a - b, b);
  } else {
    return gcd(a, b - a);
  }
}

struct ListNode* insertGreatestCommonDivisors(struct ListNode* head){
  struct ListNode* temp = head;
  while (temp->next != NULL) {
    int value = gcd(temp->val, temp->next->val);
    struct ListNode* new = malloc(sizeof(struct ListNode));
    new->val = value;
    new->next = temp->next;
    temp->next = new;
    temp = temp->next->next;
  }

  return head;
}