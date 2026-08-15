// Longest Subsequence with Non-Zero Bitwise XOR
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int res = 0;
        for (const int& num : nums) {
            res ^= num;
        }

        int n = nums.size();
        int j = n - 1;
        while (res == 0 && j >= 0) {
            res ^= nums[j --];
        }

        return j + 1;
    }
};
