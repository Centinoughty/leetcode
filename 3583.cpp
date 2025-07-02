// Count special triplets
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        long res = 0;
        unordered_map<int, int> l, r;
        for (const int num : nums) {
            r[num] ++;
        }

        for (int i = 0; i < nums.size(); i ++) {
            r[nums[i]] --;
            long freqL = l[2 * nums[i]];
            long freqR = r[2 * nums[i]];
            res += freqL * freqR;
            l[nums[i]] ++;
        }

        return res % 1000000007;
    }
};
