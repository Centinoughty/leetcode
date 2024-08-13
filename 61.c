// Rotate list

#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode* next;
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


int countNode (struct ListNode* head) {
    int count = 0;
    struct ListNode* temp = head;
    while (temp != NULL) {
        temp = temp->next;
        count ++;
    }

    return count;
}


struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (head == NULL) {
        return NULL;
    }
    int length = countNode(head);
    struct ListNode* temp = NULL;
    k %= length;
    int i = 0;
    while (i < length - k) {
        insertNode(&temp, head->val);
        head = head->next;
        i ++;
    }

    struct ListNode* new = head;

    if (head != NULL) {
        while (head->next != NULL) {
            head = head->next;
        }

        head->next = temp;
        temp = new;
    }

    return temp;
}