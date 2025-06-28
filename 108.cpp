// Convert sorted array to binary search tree
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) return nullptr;

        int mid = nums.size() / 2;
        TreeNode* root = new TreeNode(nums[mid]);

        vector<int> leftN(nums.begin(), nums.begin() + mid);
        vector<int> rightN(nums.begin() + mid + 1, nums.end());

        root->left = sortedArrayToBST(leftN);
        root->right = sortedArrayToBST(rightN);

        return root;
    }
};
