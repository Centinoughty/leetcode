// Count elements with maximum frequency
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> mp(100, 0);
        for (const int num : nums) {
            mp[num - 1] ++;
        }

        int maxFreq = 0;
        for (const int x : mp) {
            maxFreq = max(maxFreq, x);
        }

        int count = 0;
        for (const int x : mp) {
            if (x == maxFreq) count ++;
        }

        return count * maxFreq;
    }
};
