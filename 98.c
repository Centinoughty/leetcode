// Validate binary search tree
// MEDIUM

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

bool isValidBSTHelper (struct TreeNode* root, long minVal, long maxVal) {
  if (root == NULL) {
    return true;
  }

  if (root->val <= minVal || root->val >= maxVal) {
    return false;
  }

  return isValidBSTHelper(root->left, minVal, root->val) && isValidBSTHelper(root->right, root->val, maxVal);
}

bool isValidBST(struct TreeNode* root) {
  return isValidBSTHelper(root, (long)INT_MIN - 1, (long)INT_MAX + 1);
}
