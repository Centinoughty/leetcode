// Create binary tree from description
// MEDIUM

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

struct TreeNode* createNode(int val) {
  struct TreeNode* temp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
  temp->val = val;
  temp->left = NULL;
  temp->right = NULL;
  return temp;
}

struct TreeNode* createBinaryTree(int** descriptions, int descriptionsSize, int* descriptionsColSize) {
  struct TreeNode* nodes[100001] = {NULL};
  int isChild[100001] = {0};

  for (int i = 0; i < descriptionsSize; i++) {
    int parent = descriptions[i][0];
    int child = descriptions[i][1];
    int isLeft = descriptions[i][2];

    if (nodes[parent] == NULL) {
      nodes[parent] = createNode(parent);
    }

    if (nodes[child] == NULL) {
      nodes[child] = createNode(child);
    }

    if (isLeft) {
      nodes[parent]->left = nodes[child];
    } else {
      nodes[parent]->right = nodes[child];
    }
    isChild[child] = 1;
  }

  struct TreeNode* root = NULL;
  for (int i = 0; i < 100001; i++) {
    if (nodes[i] != NULL && !isChild[i]) {
      root = nodes[i];
      break;
    }
  }

  return root;
}