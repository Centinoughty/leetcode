// Binary tree postorder traversal
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
    vector<int> postorderTraversal(TreeNode* root) {
        postorder(root);
        return res;
    }

private:
    vector<int> res;

    void postorder(TreeNode* root) {
        if (root) {
            postorder(root->left);
            postorder(root->right);
            res.push_back(root->val);
        }
    }
};

// Iterative
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;

        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode* top = st.top(); st.pop();
            res.push_back(top->val);

            if (top->left) st.push(top->left);
            if (top->right) st.push(top->right);
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
