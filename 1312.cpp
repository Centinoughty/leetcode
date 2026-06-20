// Minimum Insertion Steps to Make a String Palindrome
// HARD

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = n - 1; i >= 0; i --) {
            for (int j = 0; j < n; j ++) {
                if (s[i] == s[j]) {
                    dp[i][j + 1] = 1 + dp[i + 1][j];
                } else {
                    dp[i][j + 1] = max(dp[i + 1][j + 1], dp[i][j]);
                }
            }
        }

        return n - dp[0][n];
    }
};
