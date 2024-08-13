// Add two numbers

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* createNode (int data) {
    struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
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

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct node* head = NULL;
    int carry = 0;
    int data;

    while (l1 != NULL && l2 != NULL) {
        data = l1->val + l2->val + carry;
        carry = data > 9 ? data / 10 : 0;
        data %= 10;
        insertNode(&head, data);
        l1 = l1->next;
        l2 = l2->next;
    }

    if (l2 == NULL) {
        while (l1 != NULL) {
            data = l1->val + carry;
            carry = data > 9 ? data / 10 : 0;
            data %= 10;
            insertNode(&head, data);
            l1 = l1->next;
        }
    } else if (l1 == NULL) {
        while (l2 != NULL) {
            data = l2->val + carry;
            carry = data > 9 ? data / 10 : 0;
            data %= 10;
            insertNode(&head, data);
            l2 = l2->next;
        }
    }

    if (carry != 0) {
        insertNode(&head, carry);
    }

    return head;
}