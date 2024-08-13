// Palindrome linked list
// EASY

#include <stdio.h>
#include <stdbool.h>

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


bool isPalindrome(struct ListNode* head) {
    struct ListNode* temp = head;
    struct ListNode* new = NULL;
    int count = 0;
    int flag = 0;
    while (temp != NULL) {
        temp = temp->next;
        count ++;
    }

    temp = head;
    new = head;
    for (int i = 0; i < count / 2; i ++) {
        new = new->next;
    }

    new = reverseList(new);
    while (new != NULL) {
        if (temp->val != new->val) {
            flag ++;
        }

        new = new->next;
        temp = temp->next;
    }
    
    return flag > 0 ? false : true;
}