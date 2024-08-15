// Flatten binary tree to linked list
// MEDIUM

#include <stdio.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

void flatten(struct TreeNode* root) {
  if (!root) return;

  flatten(root->left);
  flatten(root->right);

  struct TreeNode* left = root->left;
  struct TreeNode* right = root->right;
  root->left = NULL;
  root->right = left;
  struct TreeNode* rightMostNode = root;
  while (rightMostNode->right) {
    rightMostNode = rightMostNode->right;
  }

  rightMostNode->right = right;
}
