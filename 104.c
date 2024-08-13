// Maximum depth of a binary tree
// EASY

#include <stdio.h>

struct TreeNode {
  int val;
  struct TreeNode* left;
  struct TreeNode* right;
};

int maxDepth(struct TreeNode* root) {
  if (root) {
    return fmax(1 + maxDepth(root->left), 1 + maxDepth(root->right));
  } else {
    return 0;
  }
}