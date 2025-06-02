// Merge two sorted lists
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
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* res = NULL;
    while (list1 && list2) {
      ListNode* temp;
      if (list1->val > list2->val) {
        temp = new ListNode(list2->val);
        list2 = list2->next;
      } else {
        temp = new ListNode(list1->val);
        list1 = list1->next;
      }

      if (!res) {
        res = temp;
      } else {
        temp->next = res;
        res = temp;
      }
    }

    while (list1) {
      ListNode* temp = new ListNode(list1->val);
      temp->next = res;
      res = temp;
      list1 = list1->next;
    }

    while (list2) {
      ListNode* temp = new ListNode(list2->val);
      temp->next = res;
      res = temp;
      list2 = list2->next;
    }

    return reverse(res);
  }

private:
  ListNode* reverse(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* next = NULL;
    while (curr) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }

    return prev;
  }
};
