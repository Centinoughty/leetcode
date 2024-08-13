// Construct binary tree from preorder and inorder traversal
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

struct TreeNode* build (int* preorder, int left1, int right1, int* inorder, int left2, int right2) {
  if (left1 >= right1 || left2 >= right2) {
    return NULL;
  }

  struct TreeNode* temp = createNode(preorder[left1]);
  int mid = findIndex(inorder, left2, right2, temp->val);
  int leftSubTreeSize = mid - left2;
  temp->left = build(preorder, left1 + 1, left1 + 1 + leftSubTreeSize, inorder, left2, mid);
  temp->right = build(preorder, left1 + 1 + leftSubTreeSize, right1, inorder, mid + 1, right2);

  return temp;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
  struct TreeNode* root = NULL;
  root = build(preorder, 0, preorderSize, inorder, 0, inorderSize);
  return root;
}
