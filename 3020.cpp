// Find the Maximum Number of Elements in Subset
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        map<long, int> mp;
        mp[1] = 0;
        for (const int& num : nums) {
            mp[num] ++;
        }

        int maxLen = mp[1] % 2 ? mp[1] : mp[1] - 1;
        for (const auto& [x, y] : mp) {
            if (x == 1) continue;
            if (y > 1 && mp.find((long)x * x) != mp.end()) continue;

            int len = 1;
            double sqrtVal = sqrt(x);
            while (sqrtVal == (int)sqrtVal) {
                if (mp[sqrtVal] >= 2) {
                    sqrtVal = sqrt(sqrtVal);
                    len += 2;
                } else {
                    break;
                }
            }

            maxLen = max(maxLen, len);
        }

        return maxLen;
    }
};
