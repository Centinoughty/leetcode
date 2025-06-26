// Binary tree zigzag level order traversal
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
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if (root == nullptr) {
      return {};
    }

    vector<vector<int>> res;
    queue<TreeNode*> q{{root}};
    int flag = 0;

    while (!q.empty()) {
      int levelSize = q.size();
      vector<int> arr;
      
      for (int i = 0; i < levelSize; i ++) {
        TreeNode* temp = q.front();
        q.pop();
        arr.push_back(temp->val);

        if (temp->left) {
          q.push(temp->left);
        }

        if (temp->right) {
          q.push(temp->right);
        }
      }

      if (flag) {
        reverse(arr);
      }

      flag ^= 1;
      res.push_back(arr);
    }

    return res;
  }

  void reverse (vector<int>& nums) {
    int numsSize = nums.size();
    for (int i = 0; i < numsSize / 2; i ++) {
      int temp = nums[i];
      nums[i] = nums[numsSize - i - 1];
      nums[numsSize - i - 1] = temp;
    }
  }
};

// Using deque without reversing the array
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        bool flag = true;
        deque<TreeNode*> dq;
        if (root) {
            dq.push_back(root);
        }

        while (!dq.empty()) {
            int size = dq.size();
            vector<int> temp;
            for (int i = 0; i < size; i ++) {
                TreeNode* top;
                if (flag) {
                    top = dq.front();
                    dq.pop_front();
                    temp.push_back(top->val);
                    if (top->left) dq.push_back(top->left);
                    if (top->right) dq.push_back(top->right);
                } else {
                    top = dq.back();
                    dq.pop_back();
                    temp.push_back(top->val);
                    if (top->right) dq.push_front(top->right);
                    if (top->left) dq.push_front(top->left);
                }
            }

            res.push_back(temp);
            flag = !flag;
        }

        return res;
    }
};
