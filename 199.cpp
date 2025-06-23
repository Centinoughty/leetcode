// Binary tree right side view
// MEDIUM

#include <iostream>
#include <vector>
#include <queue>

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
	vector<int> rightSideView(TreeNode* root) {
		if (root == nullptr) {
			return {};
		}

		vector<int> res;
		queue<TreeNode*> q{{root}};

		while (!q.empty()) {
				int levelSize = q.size();
			for (int i = 0; i < levelSize; i ++) {
				TreeNode* temp = q.front();
				q.pop();

				if (i == levelSize - 1) {
					res.push_back(temp->val);
				}

				if (temp->left) {
					q.push(temp->left);
				}

				if (temp->right) {
					q.push(temp->right);
				}
			}
		}

		return res;
	}
};

// Same method but reorganized

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        levelOrder(root);
        return res;
    }

private:
    vector<int> res;

    void levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int size = q.size();
            TreeNode* rightMost = nullptr;
            for (int i = 0; i < size; i ++) {
                TreeNode* top = q.front();
                q.pop();
                if (top) {
                    rightMost = top;
                    q.push(top->left);
                    q.push(top->right);
                }
            }

            if (rightMost) {
                res.push_back(rightMost->val);
            }
        }
    }
};

// DFS Solution
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        dfs(root, 0);
        return res;
    }

private:
    vector<int> res;

    void dfs(TreeNode *root, int depth) {
        if (!root) return;

        if (depth == res.size()) {
            res.push_back(root->val);
        }

        dfs(root->right, depth + 1);
        dfs(root->left, depth + 1);
    }
};
