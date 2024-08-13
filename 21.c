// Merge two sorted lists
// EASY

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* createNode (int val) {
    struct ListNode* temp = malloc(sizeof(struct ListNode));
    temp->val = val;
    temp->next = NULL;
    return temp;
}


void insertNode (struct ListNode** head, int val) {
    if (*head == NULL) {
        *head = createNode(val);
    } else {
        struct ListNode* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = createNode(val);
    }
}


struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* head = NULL;
    while (list1 != NULL && list2 != NULL) {
        if (list1->val > list2->val) {
            insertNode(&head, list2->val);
            list2 = list2->next;
        } else {
            insertNode(&head, list1->val);
            list1 = list1->next;
        }
    }

    if (list1 == NULL) {
        while (list2 != NULL) {
            insertNode(&head, list2->val);
            list2 = list2->next;
        }
    }

    if (list2 == NULL) {
        while (list1 != NULL) {
            insertNode(&head, list1->val);
            list1 = list1->next;
        }
    }

    return head;
}