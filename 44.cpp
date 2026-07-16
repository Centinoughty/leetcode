// Wildcard Matching
// HARD

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();

        vector<vector<int>> dp;
        dp.resize(m + 1, vector<int>(n + 1, 0));
        dp[m][n] = 1;

        int j = n - 1;
        while (j >= 0 && p[j] == '*') {
            dp[m][j] = 1;
            j --;
        }

        for (int i = m - 1; i >= 0; i --) {
            for (int j = n - 1; j >= 0; j --) {
                if (p[j] == '*') {
                    dp[i][j] = dp[i][j + 1] || dp[i + 1][j];
                } else if (p[j] == '?' || s[i] == p[j]) {
                    dp[i][j] = dp[i + 1][j + 1];
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        
        return dp[0][0];
    }
};
