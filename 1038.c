// Binary search tree to greater sum tree
// MEDIUM

#include <stdio.h>

struct TreeNode {
  int val;
  struct TreeNode* left;
  struct TreeNode* right;
};

void gstHelper (struct TreeNode* root, int* prefix) {
  if (root == NULL) {
    return;
  } else {
    gstHelper(root->right, prefix);
    root->val += *prefix;
    *prefix = root->val;
    gstHelper(root->left, prefix);
  }
}

struct TreeNode* bstToGst(struct TreeNode* root) {
  int prefix = 0;
  gstHelper(root, &prefix);
  return root;
}
