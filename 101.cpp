// Symmetric tree
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
    bool isSymmetric(TreeNode* root) {
        if (root) {
            return checkSymmetry(root->left, root->right);
        }

        return true;
    }

private:
    bool checkSymmetry(TreeNode* r1, TreeNode* r2) {
        if (!r1 && !r2) return true;
        if (r1 && r2) {
            if (r1->val == r2->val) {
                return checkSymmetry(r1->left, r2->right) && checkSymmetry(r1->right, r2->left);
            }
        }

        return false;
    }
};
