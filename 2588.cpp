// Count the Number of Beutiful Subarrays
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        unordered_map<int, int> mp;
        long long cnt = 0;
        int prefix = 0;
        for (const int& num : nums) {
            prefix ^= num;
            if (prefix == 0) {
                cnt ++;
            }

            if (mp.find(prefix) != mp.end()) {
                cnt += mp[prefix];
            }

            mp[prefix] ++;
        }

        return cnt;
    }
};
