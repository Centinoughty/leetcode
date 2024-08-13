// Insert into a binary search tree
// MEDIUM

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

struct TreeNode* createNode (int val) {
  struct TreeNode* temp = malloc(sizeof(struct TreeNode));
  temp->val = val;
  temp->left = temp->right = NULL;
  return temp;
}

void insertNode(struct TreeNode** root, int val) {
  if (*root == NULL) {
    *root = createNode(val);
    return;
  } else if ((*root)->val > val) {
    insertNode(&(*root)->left, val);
  } else {
    insertNode(&(*root)->right, val);
  }
}

struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
  struct TreeNode* temp = root;
  insertNode(&temp, val);
  return temp;
}
