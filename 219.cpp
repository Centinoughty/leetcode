// Contains duplicate II
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int i = 0, j = 0;
        multiset<int> st;
        while (j <= k && j < nums.size()) {
            if (st.count(nums[j])) {
                return true;
            }

            st.insert(nums[j ++]);
        }

        while (j < nums.size()) {
            auto first = st.find(nums[i]);
            st.erase(first);

            if (st.count(nums[j])) {
                return true;
            }

            st.insert(nums[j]);
            i ++;
            j ++;
        }

        return false;
    }
};
