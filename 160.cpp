// Intersection of two linked list
// EASY

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* l1 = headA;
    ListNode* l2 = headB;
    while (l1 || l2) {
      if (l1 == l2) {
        return l1;
      } else {
        if (l1) {
          l1 = l1->next;
        } else {
          l1 = headA;
        }

        if (l2) {
          l2 = l2->next;
        } else {
          l2 = headB;
        }
      }
    }

    return NULL;
  }
};
