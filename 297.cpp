// Serialize and deserialize binary tree
// HARD

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        queue<TreeNode*> q;

        res += getValue(root);
        if (root) {
            q.push(root);
        }

        while (!q.empty()) {
            TreeNode* top = q.front();
            q.pop();
            res += "." + getValue(top->left);
            res += "." + getValue(top->right);
            if (top->left) {
                q.push(top->left);
            }

            if (top->right) {
                q.push(top->right);
            }
        }

        return res;
    }

    string getValue(TreeNode* root) {
        return root ? to_string(root->val) : "null";
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (!data.length()) return nullptr;

        vector<string> nums = split(data, '.');
        if (nums[0] == "null") return nullptr;

        TreeNode* root = new TreeNode(stoi(nums[0]));
        queue<TreeNode*> q;
        if (root) {
            q.push(root);
        }

        int i = 1;
        while (!q.empty() && i < nums.size()) {
            TreeNode* curr = q.front();
            q.pop();

            if (i < nums.size() && nums[i] != "null") {
                curr->left = new TreeNode(stoi(nums[i]));
                q.push(curr->left);
            }

            i ++;
            if (i < nums.size() && nums[i] != "null") {
                curr->right = new TreeNode(stoi(nums[i]));
                q.push(curr->right);
            }

            i ++;
        }

        return root;
    }

    vector<string> split(string s, char c) {
        vector<string> res;
        int i = 0;
        while (i < s.length()) {
            int j = i;
            string temp;
            while (j < s.length() && s[j] != '.') {
                temp += s[j ++];
            }

            res.push_back(temp);
            i = j + 1;
        }

        return res;
    }
};
