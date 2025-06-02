// Remove nth node from end of list
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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    int length = 0;
    ListNode* temp = head;
    while (temp) {
      length ++;
      temp = temp->next;
    }

    int pos = length - n;
    if (!pos) {
      return head ? head->next : NULL;
    }

    int i = 0;
    temp = head;
    ListNode* curr = temp;
    while (i < pos - 1) {
      curr = curr->next;
      i ++;
    }

    curr->next = curr->next ? curr->next->next : NULL;
    return temp;
  }
};

// Using slow and fast pointer
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* slow = head;
    ListNode* fast = head;
    for (int i = 0; i < n; i ++) {
      fast = fast->next;
    }

    if (!fast) {
      return head->next;
    }

    while (fast->next) {
      slow = slow->next;
      fast = fast->next;
    }

    ListNode* temp = slow->next;
    slow->next = slow->next->next;
    delete temp;
    return head;
  }
};
