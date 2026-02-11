// Minimum removals to balance array
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int l = 0;
        int maxLen = 0;

        for (int r = 0; r < nums.size(); r ++) {
            while ((long)nums[l] * k < nums[r]) {
                l ++;
            }

            maxLen = max(maxLen, r - l + 1);
        }

        return n - maxLen;
    }
};
