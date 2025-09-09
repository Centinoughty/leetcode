// Number of people aware of a secret
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1e9 + 7;
        vector<long long> dp(n);
        dp[0] = 1;
        long long cnt = 0;

        for (int i = 1; i < n; i ++) {
            cnt = cnt + (i - delay < 0 ? 0 : dp[i - delay]) - (i - forget < 0 ? 0 : dp[i - forget]);
            cnt = (cnt % MOD + MOD) % MOD;
            dp[i] = cnt;
        }

        long long sum = 0;
        for (int i = n - forget; i < n; i ++) {
            sum = (sum + dp[i]) % MOD;
        }

        return sum % MOD;
    }
};
