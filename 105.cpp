// Construct binary tree from preorder and inorder traversal
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (inorder.size() == 0) return NULL;

        TreeNode* temp = new TreeNode(preorder[0]);
        int pos = findIdx(preorder[0], inorder);
        vector<int> tempP(preorder.begin() + 1, preorder.begin() + 1 + pos);
        vector<int> tempI(inorder.begin(), inorder.begin() + pos);
        temp->left = buildTree(tempP, tempI);
        vector<int> newP(preorder.begin() + pos + 1, preorder.end());
        vector<int> newI(inorder.begin() + pos + 1, inorder.end());
        temp->right = buildTree(newP, newI);

        return temp;
    }

private:
    int findIdx(int val, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i ++) {
            if (inorder[i] == val) {
                return i;
            }
        }

        return -1;
    }
};
