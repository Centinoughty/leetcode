// Maximum twin sum of a linked list
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  int pairSum(ListNode* head) {
    vector<int> nums;
    ListNode* temp = head;
    while (temp) {
      nums.push_back(temp->val);
      temp = temp->next;
    }

    int maxi = 0;
    int n = nums.size();
    for (int i = 0; i < n / 2; i ++) {
      maxi = max(maxi, nums[i] + nums[n - i - 1]);
    }

    return maxi;
  }
};
