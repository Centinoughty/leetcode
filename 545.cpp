// Boundary of binary tree
// MEDIUM
// PREMIUM

#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    vector<int> boundaryTraversal(Node *root) {
        if (root) {
            res.push_back(root->data);
            leftSide(root->left);
            leafNodes(root->left);
            leafNodes(root->right);
            rightSide(root->right);
        }
        
        return res;
    }

private:
    vector<int> res;

    bool isLeaf(Node* root) {
        if (root) {
            if (!root->left && !root->right) {
                return true;
            }
        }
        
        return false;
    }

    void leftSide(Node* root) {
        while (root && !isLeaf(root)) {
            res.push_back(root->data);
            if (root->left) {
                root = root->left;
            } else {
                root = root->right;
            }
        }
    }
    
    void leafNodes(Node* root) {
        if (root) {
            leafNodes(root->left);
            if (isLeaf(root)) {
                res.push_back(root->data);
            }

            leafNodes(root->right);
        }
    }
    
    void rightSide(Node* root) {
        if (!root || isLeaf(root)) return;
        
        if (root->right) {
            rightSide(root->right);
        } else {
            rightSide(root->left);
        }
        
        res.push_back(root->data);
    }
};
