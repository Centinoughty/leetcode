// Minimum Total Cost to Process All Elements
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        long long sum = 0;
        for (const int& num : nums) {
            sum += num;
        }

        long long totalK = (sum + k - 1) / k;
        __int128 res = (__int128)totalK * (totalK - 1) / 2;
        return res % MOD;
    }
};
