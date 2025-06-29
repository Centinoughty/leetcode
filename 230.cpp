// kth smallest element in BST
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
  int kthSmallest(TreeNode* root, int k) {
    int val = 0;
    inorder(root, val, k);
    return val;
  }

  void inorder (TreeNode* root, int& val, int& k) {
    if (root) {
      inorder(root->left, val, k);
      if (k == 1) {
        val = root->val;
        k = 0;
        return;
      }
      k --;
      inorder(root->right, val, k);
    }
  }
};

// Using extra space
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        inorder(root);
        return inorderArr[k - 1];
    }

private:
    vector<int> inorderArr;

    void inorder(TreeNode* root) {
        if (root) {
            inorder(root->left);
            inorderArr.push_back(root->val);
            inorder(root->right);
        }
    }
};
