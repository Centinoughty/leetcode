// Path sum
// EASY

#include <stdio.h>
#include <stdbool.h>

struct TreeNode {
  int val;
  struct TreeNode* left;
  struct TreeNode* right;
};

bool hasPathSum(struct TreeNode* root, int targetSum) {
  if (root == NULL) {
    return false;
  }

  if (root->val == targetSum && !root->left && !root->right) {
    return true;
  }

  return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
}