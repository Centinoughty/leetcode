// Lowest common ancestor of a binary search tree
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val > q->val) {
            return lowestCommonAncestor(root, q, p);
        }

        TreeNode* temp = root;
        int valP = p->val, valQ = q->val;

        while (temp && !(temp->val >= valP && temp->val <= valQ)) {
            if (valP > temp->val) {
                temp = temp->right;
            } else {
                temp = temp->left;
            }
        }

        return temp;
    }
};

// Recursive approach
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val > q->val) {
            return lowestCommonAncestor(root, q, p);
        }

        int valP = p->val, valQ = q->val;
        if (valP > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        } else if (valQ < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        } else {
            return root;
        }
    }
};
