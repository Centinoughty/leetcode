// Construct binary tree from preorder and postorder traversal
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
  TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
    int preIdx = 0;
    return constructTree(preorder, postorder, preIdx, 0, preorder.size() - 1, preorder.size());
  }

private:
  TreeNode* constructTree(vector<int>& preorder, vector<int>& postorder, int& preIdx, int left, int right, int size) {
    if (preIdx >= size || left > right) {
      return nullptr;
    }

    TreeNode* root = new TreeNode(preorder[preIdx]);
    preIdx ++;

    if (left == right) {
      return root;
    }

    int i;
    for (i = left; i <= right; i ++) {
      if (preorder[preIdx] == postorder[i]) {
        break;
      }
    }

    if (i <= right) {
      root->left = constructTree(preorder, postorder, preIdx, left, i, size);
      root->right = constructTree(preorder, postorder, preIdx, i + 1, right - 1, size);
    }

    return root;
  }
};