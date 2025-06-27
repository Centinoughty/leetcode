// Construct binary tree from inorder and postorder traversal
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.size() == 0) return NULL;

        TreeNode* temp = new TreeNode(postorder[postorder.size() - 1]);
        int pos = findIdx(temp->val, inorder);
        vector<int> tempP(postorder.begin(), postorder.begin() + pos);
        vector<int> tempI(inorder.begin(), inorder.begin() + pos);
        temp->left = buildTree(tempI, tempP);
        vector<int> newP(postorder.begin() + pos, postorder.end() - 1);
        vector<int> newI(inorder.begin() + pos + 1, inorder.end());
        temp->right = buildTree(newI, newP);

        return temp;
    }

private:
    int findIdx(int val, vector<int> inorder) {
        for (int i = 0; i < inorder.size(); i ++) {
            if (inorder[i] == val) {
                return i;
            }
        }

        return -1;
    }
};
