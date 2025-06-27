// Search in a binary search tree
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
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* temp = root;
        while (temp && temp->val != val) {
            if (temp->val > val) {
                temp = temp->left;
            } else {
                temp = temp->right;
            }
        }

        return temp;
    }
};
