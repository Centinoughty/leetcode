// Maximum sum bst in binary tree
// HARD

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
    int maxSumBST(TreeNode* root) {
        postorder(root);
        return maxSum;
    }

private:
    int maxSum = 0;

    tuple<bool, int, int, int> postorder(TreeNode* root) {
        if (!root) return {true, 0, INT_MAX, INT_MIN};

        auto [isLeft, leftSum, leftMin, leftMax] = postorder(root->left);
        auto [isRight, rightSum, rightMin, rightMax] = postorder(root->right);

        if (isLeft && isRight && leftMax < root->val && root->val < rightMin) {
            int sum = leftSum + rightSum + root->val;
            maxSum = max(maxSum, sum);
            int minVal = min(leftMin, root->val);
            int maxVal = max(root->val, rightMax);
            return {true, sum, minVal, maxVal};
        }

        return {false, 0, 0, 0};
    }
};
