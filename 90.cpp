// SUbsets II
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        set<vector<int>> st;
        for (int i = 0; i < (1 << nums.size()); i ++) {
            vector<int> temp;
            for (int j = 0; j < nums.size(); j ++) {
                if (i & (1 << j)) {
                    temp.push_back(nums[j]);
                }
            }

            st.insert(temp);
        }

        for (auto& v : st) {
            res.push_back(v);
        }

        return res;
    }
};
