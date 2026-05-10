// Minimum flips to make binary string coherent
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        if (n < 3) return 0;

        int cnt0 = 0, cnt1 = 0;
        for (const char& c: s) {
            if (c == '0') cnt0 ++;
            else cnt1 ++;
        }

        int x = cnt0;
        int y = max(0, cnt1 - 1);
        int z = cnt1 - (s[0] - '0') - (s[n - 1] - '0');

        return min(x, min(y, z));
    }
};
