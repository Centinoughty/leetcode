// Binary tree paths
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (!root) return res;

        stack<pair<TreeNode*, string>> st;
        st.push({root, to_string(root->val)});
        while (!st.empty()) {
            auto top = st.top();
            st.pop();

            if (isLeaf(top.first)) {
                res.push_back(top.second);
            }

            if (top.first->right) {
                st.push({top.first->right, top.second + "->" + to_string(top.first->right->val)});
            }

            if (top.first->left) {
                st.push({top.first->left, top.second + "->" + to_string(top.first->left->val)});
            }
        }

        return res;
    }

private:
    bool isLeaf(TreeNode* root) {
        if (root) {
            if (!root->left && !root->right) {
                return true;
            }
        }

        return false;
    }
};
