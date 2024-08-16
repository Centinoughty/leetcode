// Binary tree level order traversal
// MEDIUM

#include <iostream>
#include <vector>
#include <queue>

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
  vector<vector<int>> levelOrder(TreeNode* root) {
    if (root == nullptr) {
      return {};
    }

    vector<vector<int>> res;
    queue<TreeNode*> q{{root}};

    while (!q.empty()) {
      int levelSize = q.size();
      vector<int> arr;
      for (int i = 0; i < levelSize; i ++) {
        TreeNode* temp = q.front();
        q.pop();
        arr.push_back(temp->val);

        if (temp->left) {
          q.push(temp->left);
        }

        if (temp->right) {
          q.push(temp->right);
        }
      }

      res.push_back(arr);
    }

    return res;
  }
};
