// Longest substring without repeating charecters

#include <stdio.h>

struct node {
    char data;
    struct node* next;
};

struct node* createNode (char data) {
    struct node* temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;

    return temp;
}


void insertNode (struct node** head, char data) {
    if (*head == NULL) {
        *head = createNode(data);
    } else {
        struct node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = createNode(data);
    }
}


int searchList (struct node* head, char data) {
    struct node* temp = head;
    if(temp == NULL) {
        return 0;
    }

    while (temp != NULL) {
        if (temp->data == data) {
            return 1;
        }

        temp = temp->next;
    }

    return 0;
}


void deleteList (struct node** head) {
    while (*head != NULL) {
        struct node* temp = (*head)->next;
        (*head)->next == NULL;
        free(*head);
        *head = NULL;
    }
}


int lengthOfLongestSubstring(char* s) {
    struct node* head = NULL;
    int i = 0, count = 0, maxCount = 0;
    while (s[i] != '\0') {
        if (!searchList(head, s[i])) {
            insertNode(&head, s[i]);
            count ++;
            maxCount = count > maxCount ? count : maxCount;
        } else {
            while (head->data != s[i]) {
                struct node* temp = head->next;
                head->next = NULL;
                free(head);
                head = temp;
                count --;
            }

            head = head->next;
            insertNode(&head, s[i]);
        }

        i ++;
    }

    return maxCount;
}