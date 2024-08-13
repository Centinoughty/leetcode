// Remove duplicates from sorted list
// EASY

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* createNode (int data) {
    struct ListNode* temp = malloc(sizeof(struct ListNode));
    temp->val = data;
    temp->next = NULL;

    return temp;
}


void insertNode (struct ListNode** head, int data) {
    if (*head == NULL) {
        *head = createNode(data);
    } else {
        struct ListNode* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = createNode(data);
    }
}


struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* temp = head;
    while (temp != NULL && temp->next != NULL) {
        if (temp->val == temp->next->val) {
            temp->next = temp->next->next;
        } else {
            temp = temp->next;
        }
    }

    return head;
}