// Longest common subsequence
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int l1 = text1.length(), l2 = text2.length();
        vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));

        for (int i = 0; i < l1; i ++) {
            for (int j = 0; j < l2; j ++) {
                if (text1[i] == text2[j]) {
                    dp[i + 1][j + 1] = 1 + dp[i][j];
                } else {
                    dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
                }
            }
        }

        return dp[l1][l2];
    }
};
