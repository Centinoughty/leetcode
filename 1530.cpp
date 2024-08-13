// Number of good leaf nodes pairs
// MEIDUM

#include <iostream>
#include <vector>

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
  int countPairs(TreeNode* root, int distance) {
    int result = 0;
    helper(root, distance, &result);
    return result;
  }

private:
  vector<int> helper(TreeNode* root, int distance, int* ans) {
    if (!root) return {0};
    if (root->left == NULL && root->right == NULL) return {1};

    auto left = helper(root->left, distance, ans);
    auto right = helper(root->right, distance, ans);

    for (auto x : left) {
      for (auto y : right) {
        if ((x && y) && x + y <= distance) {
          (*ans) ++;
        }
      }
    }

    vector<int> res;
    for (auto x : left) {
      if (x && x + 1 < distance) {
        res.push_back(x + 1);
      }
    }

    for (auto y : right) {
      if (y && y + 1 < distance) {
        res.push_back(y + 1);
      }
    }

    return res;
  }
};
