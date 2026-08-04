// Count Good Nodes in Binary Tree
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
    int goodNodes(TreeNode* root) {
        return findHelper(root, INT_MIN);
    }

private:
    int findHelper(TreeNode* root, int maxVal) {
        if (!root) return 0;
        
        int res = 0;
        if (root->val >= maxVal) res ++;

        res += findHelper(root->left, max(maxVal, root->val));
        res += findHelper(root->right, max(maxVal, root->val));

        return res;
    }
};
