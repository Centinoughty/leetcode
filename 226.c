// Invert binary tree
// EASY

#include <stdio.h>

struct TreeNode {
  int val;
  struct TreeNode* left;
  struct Treeenode* right;
};

struct TreeNode* invertTree(struct TreeNode* root) {
  if (root) {
    struct TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;

    invertTree(root->left);
    invertTree(root->right);
  }

  return root;
}