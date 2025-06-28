// Diameter of binary tree
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
    int diameterOfBinaryTree(TreeNode* root) {
        diameter(root);
        return maxLength;
    }

private:
    int maxLength = 0;

    bool isLeaf(TreeNode* root) {
        if (root) {
            if (!root->left && !root->right) {
                return true;
            }
        }

        return false;
    }

    int diameter(TreeNode* root) {
        if (!root) return -1;
        if (isLeaf(root)) return 0;

        int left = diameter(root->left);
        int right = diameter(root->right);
        maxLength = max(maxLength, left + right + 2);

        return 1 + max(left, right);
    }
};
