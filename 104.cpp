// Maximum depth of binary tree
// EASY

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
    int maxDepth(TreeNode* root) {
        return depth(root, 0);
    }

private:
    int depth(TreeNode* root, int height) {
        if (!root) return height;
        return max(depth(root->left, height + 1), depth(root->right, height + 1));
    }
};
