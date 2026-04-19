// Smallest stable index II
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix, suffix;

        prefix.push_back(nums[0]);
        for (int i = 1; i < n; i ++) {
            prefix.push_back(max(prefix[i - 1], nums[i]));
        }

        suffix.push_back(nums[n - 1]);
        for (int j = n - 2; j >= 0; j --) {
            suffix.push_back(min(suffix[abs(j - n + 2)], nums[j]));
        }

        reverse(suffix.begin(), suffix.end());

        for (int i = 0; i < nums.size(); i ++) {
            if (prefix[i] - suffix[i] <= k) return i;
        }

        return -1;
    }
};
