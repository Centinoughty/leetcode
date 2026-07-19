// Count Dominant Nodes in a Binary Tree
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
    int countDominantNodes(TreeNode* root) {
        domHelper(root);
        return cnt;
    }

private:
    int cnt = 0;
    
    int domHelper(TreeNode* root) {
        if (!root) return INT_MIN;

        int l = domHelper(root->left);
        int r = domHelper(root->right);

        if (root->val >= l && root->val >= r) {
            cnt ++;
        }

        return max(root->val, max(l, r));
    }
};
