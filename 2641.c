// Cousins in binary tree II
// MEDIUM

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

struct TreeNode* createNode (int data) {
  struct TreeNode* temp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
  temp->val = data;
  temp->left = temp->right = NULL;
  return temp;
}

int height (struct TreeNode* root) {
  if (!root) {
    return 0;
  }

  return 1 + fmax(height(root->left), height(root->right));
}

void findLevelSum (struct TreeNode* root, int* arr, int level) {
  if (!root) {
    return;
  }

  arr[level] += root->val;
  findLevelSum(root->left, arr, level + 1);
  findLevelSum(root->right, arr, level + 1);
}

struct TreeNode* dfs (struct TreeNode* parent, struct TreeNode* node, int* arr, int depth) {
  struct TreeNode* temp;
  if (!node) {
    return NULL;
  } else if (depth == 0 || depth == 1) {
    temp = createNode(0);
  } else {
    int siblingSum = arr[depth];
    if (parent->right) siblingSum -= parent->right->val;
    if (parent->left) siblingSum -= parent->left->val;
    temp = createNode(siblingSum);
  }


  temp->left = dfs(node, node->left, arr, depth + 1);
  temp->right = dfs(node, node->right, arr, depth + 1);

  return temp;
}

struct TreeNode* replaceValueInTree(struct TreeNode* root) {
  int maxHeight = height(root);
  int* arr = (int*)calloc(maxHeight, sizeof(int));
  findLevelSum(root, arr, 0);
  root = dfs(NULL, root, arr, 0);
  return root;
}
