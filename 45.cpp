// Jump Game II
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        memo.resize(nums.size(), -1);
        return jumpHelper(nums, 0);
    }

private:
    vector<int> memo;

    int jumpHelper(vector<int>& nums, int pos) {
        if (pos == nums.size() - 1) {
            return 0;
        }

        if (memo[pos] != -1) {
            return memo[pos];
        }

        int res = INT_MAX;
        for (int j = 1; j <= nums[pos]; j ++) {
            if (pos + j < nums.size()) {
                int next = jumpHelper(nums, pos + j);
                if (next != INT_MAX) res = min(res, 1 + next);
            }
        }

        return memo[pos] = res;
    }
};
