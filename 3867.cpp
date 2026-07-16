// Sum of GCD of Formed Pairs
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixGcd(n);

        int prefix = nums[0];
        for (int i = 0; i < n; i ++) {
            prefix = max(prefix, nums[i]);
            prefixGcd[i] = gcd(prefix, nums[i]);
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        long long res = 0;
        for (int i = 0; i < floor((double)n / 2); i ++) {
            res += gcd(prefixGcd[i], prefixGcd[n - i - 1]);
        }

        return res;
    }
};
