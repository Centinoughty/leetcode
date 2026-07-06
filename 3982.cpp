// Sum of Integers with Maximum Digit Range
// EASY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        vector<int> mp(10, 0);
        int res = 0;
        for (const int& num : nums) {
            string s = to_string(num);

            char maxVal = s[0], minVal = s[0];
            for (int i = 1; i < s.length(); i ++) {
                maxVal = max(maxVal, s[i]);
                minVal = min(minVal, s[i]);
            }

            mp[maxVal - minVal] += num;
            res = max(res, maxVal - minVal);
        }

        return mp[res];
    }
};
