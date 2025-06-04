// Palindrome linked list
// EASY

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
  bool isPalindrome(ListNode* head) {
    ListNode *temp = head, *curr = head;
    int count = 0;
    while (curr) {
      count ++;
      curr = curr->next;
    }

    cout << ceil((double) count / 2);
    curr = temp;
    int pos = 0;
    while (pos < ceil((double) count / 2) - 1) {
      curr = curr->next;
      pos ++;
    }

    curr->next = reverse(curr->next);
    
    ListNode *copy = temp;
    pos = 0;
    curr = curr->next;
    while (pos < count / 2) {
      if (copy->val == curr->val) {
        copy = copy->next;
        curr = curr->next;
      } else {
        return false;
      }

      pos ++;
    }

    return true;
  }

private:
    ListNode* reverse(ListNode* head) {
      ListNode *prev = NULL, *curr = head, *next = NULL;
      while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
      }

      return prev;
    }
};
