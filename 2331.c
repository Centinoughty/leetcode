// Evaluate boolean binary tree
// EASY

#include <stdio.h>
#include <stdbool.h>

struct TreeNode {
  int val;
  struct TreeNode* left;
  struct TreeNode* right;
  
};

struct TreeNode* evaluate (struct TreeNode* root) {
  if (root == NULL) {
    return NULL;
  }

  root->left = evaluate(root->left);
  root->right = evaluate(root->right);
  if (root->val == 2) {
    root->val = root->left->val | root->right->val;
  } else if (root->val == 3) {
    root->val = root->left->val & root->right->val;
  }

  return root;
}

bool evaluateTree(struct TreeNode* root) {
  return evaluate(root)->val;
}

bool evaluateTree(struct TreeNode* root) {
  if (root->val < 2) {
    return root->val;
  } else if (root->val == 2) {
    return evaluateTree(root->left) || evaluateTree(root->right);
  } else {
    return evaluateTree(root->left) && evaluateTree(root->right);
  }
}