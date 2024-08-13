// Diameter of binary tree
// EASY

#include <stdio.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

int maxDepth (struct TreeNode* root) {
  if (!root) {
    return 0;
  }

  return 1 + fmax(maxDepth(root->left), maxDepth(root->right));
}

int diameterOfBinaryTree(struct TreeNode* root) {
  if (!root) {
    return 0;
  }

  int leftHeight = maxDepth(root->left);
  int rightHeight = maxDepth(root->right);

  int leftDiameter = diameterOfBinaryTree(root->left);
  int rightDiameter = diameterOfBinaryTree(root->right);

  return fmax(leftHeight + rightHeight, fmax(leftDiameter, rightDiameter));
}
