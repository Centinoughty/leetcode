// Populating next right pointers in each node
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        if (root) {
            q.push(root);
        }

        while (!q.empty()) {
            int size = q.size();
            Node* prev = NULL;
            for (int i = 0; i < size; i ++) {
                Node* top = q.front();
                if (prev) {
                    prev->next = top;
                }

                q.pop();
                prev = top;
                if (top->left) {
                    q.push(top->left);
                }

                if (top->right) {
                    q.push(top->right);
                }

                if (i == size - 1) {
                    top->next = NULL;
                }
            }
        }

        return root;
    }
};
