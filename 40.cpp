// Combination sum II
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target);
        return res;
    }

private:
    vector<vector<int>> res;
    vector<int> st;
    void dfs(vector<int> nums, int i, int target) {
        if (target == 0) {
            res.push_back(st);
            return;
        }

        for (int j = i; j < nums.size(); j ++) {
            if (j > i && nums[j] == nums[j - 1]) continue;
            if (nums[j] > target) break;
            st.push_back(nums[j]);
            dfs(nums, j + 1, target - nums[j]);
            st.pop_back();
        }
    }
};
