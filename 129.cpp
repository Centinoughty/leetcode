// Sum root to leaf numbers
// MEDIUM

#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  int sumNumbers(TreeNode* root) {
    updateTree(root);
    int res = findSum(root);
    return res;
  }

  int findSum(TreeNode* root) {
    if (!root) {
      return 0;
    }

    int sum = 0;
    if (!root->left && !root->right) {
      sum += root->val;
    }

    return sum + findSum(root->left) + findSum(root->right);
  }

  void updateTree (TreeNode* root) {
    if (!root) {
      return;
    }

    if (root->left) {
      root->left->val += root->val * 10;
      updateTree(root->left);
    }

    if (root->right) {
      root->right->val += root->val * 10;
      updateTree(root->right);
    }
  }
};
