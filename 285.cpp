// Inorder successor in bst
// MEDIUM
// PREMIUM

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
public:
    int inOrderSuccessor(Node *root, Node *x) {
        Node *succ = nullptr, *temp = root;
        while (temp) {
            if (temp->data > x->data) {
                succ = temp;
                temp = temp->left;
            } else {
                temp = temp->right;
            }
        }
        
        return succ ? succ->data : -1;
    }
};
