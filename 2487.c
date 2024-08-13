// Remove nodes from a linked list
// MEDIUM

#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* removeNodes(struct ListNode* head) {
    if (head == NULL) {
        return NULL;
    }

    head->next = removeNodes(head->next);
    return head->next != NULL && head->val < head->next->val ? head->next : head;
}