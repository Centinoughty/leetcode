// Rotate list
// MEDIUM

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
  ListNode* rotateRight(ListNode* head, int k) {
    if (!head) return NULL;

    int n = 0;
    ListNode *temp = NULL, *curr = head;
    while (curr) {
      curr = curr->next;
      n ++;
    }

    k = k % n;
    if (k % n == 0) return head;

    k = n - k;

    curr = head;
    for (int i = 1; i < k; i ++) {
      curr = curr->next;
    }

    ListNode *next = curr->next;
    while (next && next->next) {
      next = next->next;
    }

    next->next = head;
    temp = curr->next;
    curr->next = NULL;

    return temp;
  }
};
