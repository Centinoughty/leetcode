// Merge in Between Linked List

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
};

struct node* merge (struct node* list1, int a, int b, struct node* list2) {
    struct node* start = list1, * end = list2;
    for (int i = 0; i < b; i ++) {
        start = start->link;
    }

    while (end->link) {
        end = end->link;
    }

    end->link = start->link;
    start = list1;

    for (int i = 0; i < a - 1; i ++) {
        start = start->link;
    }

    start->link = list2;

    return list1;
}