// Amount of Time for Binary Tree to Be Infected
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
    int amountOfTime(TreeNode* root, int start) {
        fillParent(root, nullptr);
        TreeNode* target = findNode(root, start);

        queue<TreeNode*> q;
        q.push(target);

        int timer = -1;
        while (!q.empty()) {
            int size = q.size();
            timer ++;

            while (size --) {
                TreeNode* top = q.front(); q.pop();
                visited.insert(top);

                if (top->left && visited.count(top->left) == 0) q.push(top->left);
                if (top->right && visited.count(top->right) == 0) q.push(top->right);
                if (parent[top] && visited.count(parent[top]) == 0) q.push(parent[top]);
            }
        }

        return timer;
    }

private:
    unordered_set<TreeNode*> visited;
    unordered_map<TreeNode*, TreeNode*> parent;

    TreeNode* findNode(TreeNode* root, int val) {
        if (!root) return nullptr;
        if (root->val == val) return root;

        TreeNode* l = findNode(root->left, val);
        TreeNode* r = findNode(root->right, val);

        if (l) return l;
        return r;
    }

    void fillParent(TreeNode* root, TreeNode* p) {
        if (!root) return;
        parent[root] = p;

        fillParent(root->left, root);
        fillParent(root->right, root);
    }
};
