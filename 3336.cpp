// Find the Number of Subsequences with Equal GCD
// HARD

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        int m = *max_element(nums.begin(), nums.end());

        vector<vector<vector<int>>> dp;
        dp.resize(n + 1, vector<vector<int>>(m + 1, vector<int>(m + 1, 0)));
        dp[0][0][0] = 1;

        for (int i = 0; i < n; i ++) {
            for (int j = 0; j <= m; j ++) {
                for (int k = 0; k <= m; k ++) {
                    int val = dp[i][j][k];
                    if (val == 0) continue;

                    int div1 = gcd(nums[i], j), div2 = gcd(nums[i], k);
                    dp[i + 1][j][k] = (val + dp[i + 1][j][k]) % MOD;
                    dp[i + 1][div1][k] = (val + dp[i + 1][div1][k]) % MOD;
                    dp[i + 1][j][div2] = (val + dp[i + 1][j][div2]) % MOD;
                }
            }
        }

        int res = 0;
        for (int i = 1; i <= m; i ++) {
            res = (res + dp[n][i][i]) % MOD;
        }

        return res;
    }
};
