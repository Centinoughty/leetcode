// Double a number represented as a linked list
// MEDIUM

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

void insertNode (struct ListNode** head, int data) {
    struct ListNode* temp = malloc(sizeof(struct ListNode));
    temp->val = data;
    temp->next = *head;
    *head = temp;
}


struct ListNode* doubleIt(struct ListNode* head){
    struct ListNode* temp = NULL;
    while (head != NULL) {
        insertNode(&temp, head->val);
        head = head->next;
    }

    struct ListNode* new = NULL;
    int carry = 0;
    while (temp != NULL) {
        int product = temp->val * 2 + carry;
        carry = product / 10;
        product %= 10;
        insertNode(&new, product);
        temp = temp->next;
    }

    if (carry > 0) {
        insertNode(&new, carry);
    }

    return new;
}