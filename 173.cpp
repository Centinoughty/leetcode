// Binary search tree iterator
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

class BSTIterator {
    stack<TreeNode*> st;

public:
    BSTIterator(TreeNode* root) {
        pushNodes(root);
    }
    
    int next() {
        TreeNode* top = st.top();
        st.pop();
        pushNodes(top->right);
        return top->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }

    void pushNodes(TreeNode* root) {
        while (root) {
            st.push(root);
            root = root->left;
        }
    }
};
