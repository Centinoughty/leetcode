// Reverse odd levels of binary tree
// MEDIUM

#include <bits/stdc++.h>
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
  TreeNode* reverseOddLevels(TreeNode* root) {
    if (!root) {
      return nullptr;
    }

    rotate(root->left, root->right, 1);
    return root;
  }

private:
  void rotate (TreeNode* left, TreeNode* right, int depth) {
    if (!left || !right) {
      return;
    }

    if (depth % 2) {
      swap(left->val, right->val);
    }

    rotate(left->left, right->right, depth + 1);
    rotate(left->right, right->left, depth + 1);
  }
};
