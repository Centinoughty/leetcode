// Length of Longest Subarray with at most K frequency
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;

        int l = 0, maxLen = 0;
        for (int r = 0; r < n; r ++) {
            mp[nums[r]] ++;
            while (mp[nums[r]] > k) {
                mp[nums[l ++]] --;
            }

            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};
