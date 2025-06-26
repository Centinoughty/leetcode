// Balanced binary tree
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
    bool isBalanced(TreeNode* root) {
        bool res = true;
        height(root, res);
        return res;
    }

private:
    int height(TreeNode* root, bool& res) {
        if (!root) return 0;
        int lh = height(root->left, res);
        int rh = height(root->right, res);

        if (abs(lh - rh) > 1) {
            res = false;
        }

        return 1 + max(lh, rh);
    }
};
