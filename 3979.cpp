// Maximum Valid Pair Sum
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> suffix(n + 1, -1);
        suffix[n] = 0;
        for (int i = n - 1; i >= k; i --) {
            suffix[i] = max(suffix[i + 1], nums[i]);
        }

        int maxVal = 0;
        for (int i = 0; i < n - k; i ++) {
            maxVal = max(maxVal, nums[i] + suffix[i + k]);
        }

        return maxVal;
    }
};
