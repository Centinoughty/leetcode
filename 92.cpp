// Reverse linked list II
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
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (left == right) return head;
    ListNode temp(0);
    temp.next = head;
    ListNode* prev = &temp;

    for (int i = 0; i < left - 1; i ++) {
      prev = prev->next;
    }

    ListNode* curr = prev->next;
    for (int i = 0; i < right - left; i ++) {
      ListNode* next = curr->next;
      curr->next = next->next;
      next->next = prev->next;
      prev->next = next;
    }

    return temp.next;
  }
};
