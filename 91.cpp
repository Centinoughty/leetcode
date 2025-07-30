// Decode ways
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        dp.resize(s.length() + 1, -1);
        dp[s.length()] = 1;
        return fn(s, 0);
    }

private:
    vector<int> dp;

    int fn(string s, int pos) {
        cout << pos;
        if (dp[pos] != -1) return dp[pos];
        if (s[pos] == '0') return 0;

        int res = fn(s, pos + 1);
        if (pos + 1 < s.length() && (s[pos] == '1' || (s[pos] == '2' && s[pos + 1] <= '6'))) {
            res += fn(s, pos + 2);
        }

        dp[pos] = res;
        return res;
    }
};
