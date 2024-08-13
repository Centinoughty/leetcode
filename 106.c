// Construct binary tree from inorder and postorder traversal
// MEDIUM

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

struct TreeNode* createNode (int val) {
  struct TreeNode* temp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
  temp->val = val;
  temp->left = temp->right = NULL;
  return temp;
}

int findIndex (int* nums, int left, int right, int val) {
  for (int i = left; i < right; i ++) {
    if (nums[i] == val) {
      return i;
    }
  }

  return -1;
}

struct TreeNode* build (int* inorder, int left1, int right1, int* postorder, int left2, int right2) {
  if (left1 >= right1 || left2 >= right2) {
    return NULL;
  }

  struct TreeNode* temp = createNode(postorder[right2 - 1]);
  int mid = findIndex(inorder, left1, right1, temp->val);
  int rightSubTreeSize = right1 - mid;
  temp->left = build(inorder, left1, mid, postorder, left2, right2 - rightSubTreeSize);
  temp->right = build(inorder, mid + 1, right1, postorder, right2 - rightSubTreeSize, right2 - 1);

  return temp;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
  struct TreeNode* root = NULL;
  root = build(inorder, 0, inorderSize, postorder, 0, postorderSize);
  return root;
}
