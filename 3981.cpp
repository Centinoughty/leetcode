// Count Distinct Ways to Form Target from Two Strings
// HARD

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

class Solution {
public:
    int interleaveCharacters(string word1, string word2, string target) {
        int l1 = word1.length(), l2 = word2.length();
        int n = target.length();

        vector<vector<vector<int>>> dp;
        dp.resize(l1 + 1, vector<vector<int>>(l2 + 1, vector<int>(n + 1, 0)));

        for (int i = 1; i <= l1; i ++) {
            for (int j = 1; j <= l2; j ++) {
                dp[i][j][n] = 1;
            }
        }

        for (int pos = n - 1; pos >= 0; pos --) {
            for (int x = l1; x >= 0; x --) {
                for (int y = l2; y >= 0; y --) {
                    int res = 0;
                    for (int i = x; i < l1; i ++) {
                        if (word1[i] == target[pos]) {
                            res = (res + dp[i + 1][y][pos + 1]) % MOD;
                        }
                    }

                    for (int j = y; j < l2; j ++) {
                        if (word2[j] == target[pos]) {
                            res = (res + dp[x][j + 1][pos + 1]) % MOD;
                        }
                    }

                    dp[x][y][pos] = res % MOD;
                }
            }
        }

        return dp[0][0][0];
    }
};
