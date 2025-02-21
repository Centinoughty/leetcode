// Find elements in a contaminated binary tree
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

class FindElements {
public:
  unordered_set<int> nums;

  FindElements(TreeNode* root) {
    dfs(root, 0);
  }
  
  bool find(int target) {
    return nums.count(target);
  }

  void dfs (TreeNode* root, int val) {
    if (!root) {
      return;
    }

    root->val = val;
    nums.insert(val);
    dfs(root->left, 2 * val + 1);
    dfs(root->right, 2 * val + 2);
  }
};
