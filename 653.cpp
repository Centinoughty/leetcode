// Two sum IV - input is a bst
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
    bool findTarget(TreeNode* root, int k) {
        inorder(root);
        int i = 0, j = inorderArr.size() - 1;
        while (i < j) {
            int sum = inorderArr[i] + inorderArr[j];
            if (sum < k) {
                i ++;
            } else if (sum > k) {
                j --;
            } else {
                return true;
            }
        }

        return false;
    }

private:
    vector<int> inorderArr;

    void inorder(TreeNode* root) {
        if (root) {
            inorder(root->left);
            inorderArr.push_back(root->val);
            inorder(root->right);
        }
    }
};
