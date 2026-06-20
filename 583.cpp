// Delete Operation for Two Strings
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.length(), l2 = word2.length();
        vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));
        for (int i = 0; i < l1; i ++) {
            for (int j = 0; j < l2; j ++) {
                if (word1[i] == word2[j]) {
                    dp[i + 1][j + 1] = 1 + dp[i][j];
                } else {
                    dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
                }
            }
        }

        int lcs = dp[l1][l2];
        return l1 + l2 - 2 * lcs;
    }
};
