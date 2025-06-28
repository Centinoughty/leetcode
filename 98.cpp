// Validate binary search binary tree
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
    bool isValidBST(TreeNode* root) {
        return helperBST(root, (long)INT_MIN - 1, (long)INT_MAX + 1);
    }

private:
    bool helperBST(TreeNode* root, long mini, long maxi) {
        if (!root) return true;

        if (root->val <= mini || root->val >= maxi) {
            return false;
        }

        bool left = helperBST(root->left, mini, root->val);
        bool right = helperBST(root->right, root->val, maxi);
        return left && right;
    }
};
