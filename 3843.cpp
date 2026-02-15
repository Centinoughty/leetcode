// First element with unique frequency
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (const int num : nums) {
            mp[num] ++;
        }

        unordered_map<int, int> freq;
        for (const auto [x, y] : mp) {
            freq[y] ++;
        }

        for (const int num : nums) {
            if (freq[mp[num]] == 1) {
                return num;
            }
        }

        return -1;
    }
};
