// Add two numbers
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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* temp = l1;
    ListNode* prev = NULL;
    int carry = 0;
    while (temp && l2) {
      prev = temp;
      int sum = temp->val + l2->val + carry;
      temp->val = sum % 10;
      carry = sum / 10;
      temp = temp->next;
      l2 = l2->next;
    }

    while (temp) {
      prev = temp;
      int sum = temp->val + carry;
      temp->val = sum % 10;
      carry = sum / 10;
      temp = temp->next;
    }

    while (l2) {
      int sum = l2->val + carry;
      prev->next = new ListNode(sum % 10);
      prev = prev->next;
      carry = sum / 10;
      l2 = l2->next;
    }

    if (carry) {
      prev->next = new ListNode(carry);
    }

    return l1;
  }
};
