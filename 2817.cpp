// Minimum absolute difference between elements with constraint
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int mini = INT_MAX;
        set<int> st;

        for (int i = x; i < nums.size(); i ++) {
            st.insert(nums[i - x]);
            auto it = st.upper_bound(nums[i]);
            if (it != st.end()) mini = min(mini, abs(nums[i] - *it));
            if (it != st.begin()) mini = min(mini, abs(nums[i] - *prev(it)));
        }

        return mini;
    }
};
