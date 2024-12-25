// Find the largest value in each tree row
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
  vector<int> largestValues(TreeNode *root) {
    vector<int> arr;
    dfs(root, 0, arr);
    return arr;
  }

private:
  void dfs(TreeNode *root, int depth, vector<int> &arr) {
    if (root == nullptr) {
      return;
    }

    if (depth + 1 > arr.size()) {
      arr.push_back(root->val);
    } else {
      arr[depth] = max(arr[depth], root->val);
    }

    dfs(root->left, depth + 1, arr);
    dfs(root->right, depth + 1, arr);
  }
};