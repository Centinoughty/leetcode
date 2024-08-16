// Average of levels in binary tree
// EASY

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
  vector<double> averageOfLevels(TreeNode* root) {
    if (root == nullptr) {
      return {};
    }

    vector<double> res;
    queue<TreeNode*> q{{root}};

    while (!q.empty()) {
      int levelSize = q.size();
      double sum = 0;

      for (int i = 0; i < levelSize; i ++) {
        TreeNode* temp = q.front();
        q.pop();
        sum += temp->val;

        if (temp->left) {
          q.push(temp->left);
        }

        if (temp->right) {
          q.push(temp->right);
        }
      }

      res.push_back(sum / levelSize);
    }

    return res;
  }
};
