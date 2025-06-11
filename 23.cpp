// Merge k sorted lists
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* temp = NULL;
        for (int i = 0; i < lists.size(); i ++) {
            temp = mergeList(temp, lists[i]);
        }

        return temp;
    }

private:
    ListNode* mergeList(ListNode* l1, ListNode* l2) {
        ListNode *temp = new ListNode(0);
        temp->next = l1;
        ListNode *curr = temp;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }

            curr = curr->next;
            curr->next = NULL;
        }

        if (l1) {
            curr->next = l1;
        } else {
            curr->next = l2;
        }

        return temp->next;
    }
};
