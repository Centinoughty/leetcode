// Delete node in a linked list
// MEDIUM

#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

void deleteNode(struct ListNode* node) {
    if (node == NULL || node->next == NULL) {
        return;
    }

    node->val = node->next->val;

    struct ListNode* temp = node->next;
    node->next = node->next->next;
}