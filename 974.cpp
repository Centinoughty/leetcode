// Subarray Sums Divisible by K
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> freq(k, 0);
        
        int prefix = 0, count = 0;
        for (const int& num : nums) {
            prefix += num;
            int mod = ((prefix % k) + k) % k;
            if (mod == 0) {
                count ++;
            }

            count += freq[mod];

            freq[mod] ++;
        }

        return count;
    }
};
