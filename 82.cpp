// Remove duplicates from sorted list II
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
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode temp(0, head);
    ListNode* prev = &temp;

    while (head) {
      while (head->next && head->val == head->next->val) {
        head = head->next;
      }

      if (prev->next == head) {
        prev = prev->next;
      } else {
        prev->next = head->next;
      }

      head = head->next;
    }
  
    return temp.next;
  }
};
