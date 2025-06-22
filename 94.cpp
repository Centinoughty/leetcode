// Binary tree inorder traversal
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
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return res;
    }

private:
    vector<int> res;

    void inorder(TreeNode* root) {
        if (root) {
            inorder(root->left);
            res.push_back(root->val);
            inorder(root->right);
        }
    }
};

// Morris inorder traversal
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode *curr = root;
        while (curr) {
            if (!(curr->left)) {
                res.push_back(curr->val);
                curr = curr->right;
            } else {
                TreeNode *prev = curr->left;
                while (prev->right && prev->right != curr) {
                    prev = prev->right;
                }

                if (!(prev->right)) {
                    prev->right = curr;
                    curr = curr->left;
                } else {
                    prev->right = NULL;
                    res.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }

        return res;
    }
};
