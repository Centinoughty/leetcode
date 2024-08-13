// Swap nodes in pairs
// MEDIUM

#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode* next;
};


struct ListNode* swapPairs(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode* previous = NULL;
    struct ListNode* current = head;

    while (current != NULL && current->next != NULL) {
        struct ListNode* first = current;
        struct ListNode* second = current->next;
        
        if (previous != NULL) {
            previous->next = second;
        } else {
            head = second;
        }

        first->next = second->next;
        second->next = first;

        previous = first;
        current = first->next;
    }

    return head;
}