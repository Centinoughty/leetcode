// Construct binary search tree from preorder traversal
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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.size() == 0) return nullptr;

        TreeNode* root = new TreeNode(preorder[0]);
        int i = 1;
        while (i < preorder.size() && preorder[i] < root->val) {
            i ++;
        }

        vector<int> leftP(preorder.begin() + 1, preorder.begin() + i);
        vector<int> rightP(preorder.begin() + i, preorder.end());
        
        root->left = bstFromPreorder(leftP);
        root->right = bstFromPreorder(rightP);

        return root;
    }
};
