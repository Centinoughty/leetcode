// Combination sum
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, 0, target, st);
        return res;
    }

private:
    vector<vector<int>> res;
    vector<int> st;
    void dfs(vector<int> nums, int i, int target, vector<int> st) {
        if (i >= nums.size()) {
            if (target == 0) {
                res.push_back(st);
            }

            return;
        }

        if (target - nums[i] >= 0) {
            st.push_back(nums[i]);
            dfs(nums, i, target - nums[i], st);
            st.pop_back();
        }
        

        dfs(nums, i + 1, target, st);
    }
};