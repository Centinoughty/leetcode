// Reverse nodes in k-groups
// HARD

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    if (!head || k == 1) return head;

    ListNode *temp = new ListNode(0);
    temp->next = head;
    ListNode *curr = temp, *prev = temp, * next = temp;
    int count = 0;
    while (curr->next) {
      curr = curr->next;
      count ++;
    }

    while (count >= k) {
      curr = prev->next;
      next = curr->next;
      for (int i = 1; i < k; i ++) {
        curr->next = next->next;
        next->next = prev->next;
        prev->next = next;
        next = curr->next;
      }

      prev = curr;
      count -= k;
    }

    return temp->next;
  }
};
