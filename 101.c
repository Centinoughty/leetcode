// Symmetric tree
// EASY

#include <stdio.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

bool isSymmetricNode (struct TreeNode* leftNode, struct TreeNode* rightNode) {
    if (leftNode == NULL && rightNode == NULL) {
        return true;
    }

    if (leftNode == NULL || rightNode == NULL || leftNode->val != rightNode->val) {
        return false;
    }

    return isSymmetricNode(leftNode->left, rightNode->right) && isSymmetricNode(leftNode->right, rightNode->left);
}


bool isSymmetric(struct TreeNode* root) {
    return isSymmetricNode(root->left, root->right);
}