// Binary tree preorder traversal
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
    vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);
        return res;
    }

private:
    vector<int> res;
    void preorder(TreeNode* root) {
        if (root) {
            res.push_back(root->val);
            preorder(root->left);
            preorder(root->right);
        }
    }
};

// Iterative approach
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode *curr = root;
        if (root) {
            st.push(root);
        }

        while (!st.empty()) {
            TreeNode *top = st.top();
            st.pop();
            res.push_back(top->val);
            if (top->right) st.push(top->right);
            if (top->left) st.push(top->left);
        }

        return res;
    }
};


// Morris traversal
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode *curr = root;
        while (curr) {
            if (curr->left) {
                TreeNode *prev = curr->left;
                while (prev->right && prev->right != curr) {
                    prev = prev->right;
                }

                if (prev->right) {
                    prev->right = NULL;
                    curr = curr->right;
                } else {
                    res.push_back(curr->val);
                    prev->right = curr;
                    curr = curr->left;
                }
            } else {
                res.push_back(curr->val);
                curr = curr->right;
            }
        }

        return res;
    }
};
