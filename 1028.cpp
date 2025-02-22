// Recover a tree from preorder traversal
// HARD

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
  TreeNode* recoverFromPreorder(string traversal) {       
    int i = 0;
    return dfs(traversal, 0, i);
  }

private:
  TreeNode* dfs(string traversal, int depth, int& i) {
    int count = 0;
    while (i + count < traversal.length() && traversal[i + count] == '-') {
      count ++;
    }

    if (count != depth) {
      return nullptr;
    }

    i += depth;
    int start = i;
    while (i < traversal.length() && isdigit(traversal[i])) {
      i ++;
    }

    return new TreeNode(stoi(traversal.substr(start, i - start)), dfs(traversal, depth + 1, i), dfs(traversal, depth + 1, i));
  }
};