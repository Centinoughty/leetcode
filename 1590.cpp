// Make sum divisible by p
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long total = 0, k = 0;
        for (const int num : nums) {
            total += num;
        }

        k = total % p;

        if (k == 0) return 0;

        unordered_map<int, int> mp;
        mp[0] = -1;

        int currentSum = 0, minLen = nums.size();
        for (int i = 0; i < nums.size(); i ++) {
            currentSum = (currentSum + nums[i]) % p;
            int prefix = (currentSum - k + p) % p;

            if (mp.find(prefix) != mp.end()) {
                minLen = min(minLen, i - mp[prefix]);
            }

            mp[currentSum] = i;
        }

        return minLen == nums.size() ? -1 : minLen;
    }
};
