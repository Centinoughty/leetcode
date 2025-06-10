// Permutations
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> seen(nums.size(), 0);
        helper(nums, seen);
        return res;
    }

private:
    vector<vector<int>> res;
    vector<int> st;
    void helper(vector<int> nums, vector<int>& seen) {
        if (st.size() == nums.size()) {
            res.push_back(st);
            return;
        }

        for (int i = 0; i < nums.size(); i ++) {
            if (!seen[i]) {
                st.push_back(nums[i]);
                seen[i] ^= 1;
                helper(nums, seen);
                seen[i] ^= 1;
                st.pop_back();
            }
        }
    }
};