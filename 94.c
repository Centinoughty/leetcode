// Binary tree inorder traversal
// EASY

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
  int val;
  struct TreeNode* left;
  struct TreeNode* right;
};

void traversal(struct TreeNode* root, int* nums, int* index) {
  if (root == NULL) {
    return;
  } else {
    traversal(root->left, nums, index);
    nums[(*index) ++] = root->val;
    traversal(root->right, nums, index);
  }
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
  int* array = (int*)malloc(100 * sizeof(int));
  int pos = 0;

  traversal(root, array, &pos);
  *returnSize = pos;
  return array;
}