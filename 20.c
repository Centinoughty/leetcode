// Valid parenthesis

#include <stdio.h>

struct node {
    char data;
    struct node* right;
};

struct node* createNode (char data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->right = NULL;

    return temp;
}


void insertNode (struct node** head, char data) {
    if (*head == NULL) {
        *head = createNode(data);
    } else {
        struct node* temp = createNode(data);
        temp->right = *head;
        *head = temp;
    }
}


void pop (struct node** head) {
    if (*head == NULL) {
        return;
    } else {
        struct node* temp = *head;
        *head = (*head)->right;
        temp->right = NULL;
        free(temp);
    }
}

int isValid(char* s) {
    struct node* head = NULL;
    int i = 0;
    while (s[i] != '\0') {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            insertNode(&head, s[i]);
        } else if (head != NULL && ((s[i] == ')' && head->data == '(') ||(s[i] == '}' && head->data == '{') ||(s[i] == ']' && head->data == '['))) {
            pop(&head);
        } else {
            return 0;
        }

        i ++;
    }

    if (head == NULL) {
        free(head);
        return 1;
    }
    free(head);
    return 0;
}