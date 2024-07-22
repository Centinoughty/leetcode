// Same tree
// EASY

#include <stdio.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

bool isSame (struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL) {
        return true;
    }

    if (p == NULL || q == NULL) {
        return false;
    }

    if (p->val != q->val) {
        return false;
    }
    
    return isSame(p->left, q->left) && isSame(p->right, q->right);
}

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    return isSame(p, q);
}