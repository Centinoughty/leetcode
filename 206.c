// Reverse a Linked List
// EASY

#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* reverseList (struct ListNode* head) {
    struct ListNode* previous = NULL;
    struct ListNode* current = head;
    struct ListNode* next = NULL;

    while (current) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    return previous;
}