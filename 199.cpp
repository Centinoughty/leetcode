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
