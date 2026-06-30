// All Nodes Distance k in Binary Tree
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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        fillParent(root, nullptr);

        while (k >= 0 && target) {
            bfs(target, k);

            TreeNode* p = parent[target];
            if (p) {
                if (p->left == target) {
                    p->left = nullptr;
                } else {
                    p->right = nullptr;
                }

                target = p;
                p = parent[target];
                k --;
            } else {
                break;
            }
        }

        return low;
    }

private:
    unordered_map<TreeNode*, TreeNode*> parent;
    vector<int> low;

    void bfs(TreeNode* root, int k) {
        queue<TreeNode*> q;
        q.push(root);

        int lvl = 0;
        while (!q.empty()) {
            int size = q.size();
            if (lvl > k) break;

            while (size --) {
                TreeNode* top = q.front(); q.pop();
                if (lvl == k) low.push_back(top->val);

                if (top->left) q.push(top->left);
                if (top->right) q.push(top->right);
            }

            lvl ++;
        }
    }

    void fillParent(TreeNode* root, TreeNode* p) {
        if (!root) return;
        parent[root] = p;

        fillParent(root->left, root);
        fillParent(root->right, root);
    }
};
