// Balance a binary search tree
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
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void inOrder (struct TreeNode* root, int* nums, int* returnSize) {
	if (root == NULL) {
		return;
	} else {
		inOrder(root->left, nums, returnSize);
		nums[(*returnSize) ++] = root->val;
		inOrder(root->right, nums, returnSize);
	}
}

struct TreeNode* buildTree (int* nums, int start, int end) {
	if (start > end) {
		return NULL;
	}

	int mid = (start + end) / 2;
	struct TreeNode* temp = createNode(nums[mid]);

	temp->left = buildTree(nums, start, mid - 1);
	temp->right = buildTree(nums, mid + 1, end);

	return temp;
}

struct TreeNode* balanceBST(struct TreeNode* root) {
	int arr[10000];
	int count = 0;
	inOrder(root, arr, &count);

	int* array = (int*)malloc(count * sizeof(int));
	count = 0;
	inOrder(root, array, &count);

	return buildTree(array, 0, count - 1);
}
