// Maximu width of binary tree
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
    int widthOfBinaryTree(TreeNode* root) {
        int maxWidth = 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        if (root) {
            q.push({root, 0});
        }

        while (!q.empty()) {
            int size = q.size();
            unsigned long long left = q.front().second;
            unsigned long long right = left;
            for (int i = 0; i < size; i ++) {
                auto [node, idx] = q.front();
                q.pop();
                right = idx;
                if (node->left) {
                    q.push({node->left, 2 * idx});
                }

                if (node->right) {
                    q.push({node->right, 2 * idx + 1});
                }
            }

            maxWidth = max(maxWidth, (int)(right - left + 1));
        }

        return maxWidth;
    }
};
