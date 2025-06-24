// Vertical order traversal of a binary tree
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mp;
        queue<pair<TreeNode*, pair<int, int>>> q;

        q.push({root, {0, 0}});
        while (!q.empty()) {
            auto top = q.front();
            q.pop();

            int x = top.second.first;
            int y = top.second.second;

            mp[x][y].insert(top.first->val);

            if (top.first->left) {
                q.push({top.first->left, {x - 1, y + 1}});
            }

            if (top.first->right) {
                q.push({top.first->right, {x + 1, y + 1}});
            }
        }

        vector<vector<int>> res;
        for (auto x : mp) {
            vector<int> temp;
            for (auto y : x.second) {
                temp.insert(temp.end(), y.second.begin(), y.second.end());
            }

            res.push_back(temp);
        }

        return res;
    }
};
