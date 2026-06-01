// Contiguous Subarray Sum
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int prefix = 0;
        for (int i = 0; i < nums.size(); i ++) {
            prefix += nums[i];
            if (prefix % k == 0) {
                if (i > 0) return true;
            }

            if (mp.find(prefix % k) != mp.end()) {
                if ((i - mp[prefix % k]) >= 2) {
                    return true;
                }
            } else {
                mp[prefix % k] = i;
            }
        }

        return false;
    }
};
