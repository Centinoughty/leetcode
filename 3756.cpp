// Concatenate Non-Zero Digits and Multiply by Sum II
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> nums(n + 1, 0);
        vector<int> sum(n + 1, 0), cnt(n + 1, 0);

        vector<long long> pow10(n + 1);
        pow10[0] = 1;
        for (int i = 1; i <= n; i++) {
            pow10[i] = pow10[i - 1] * 10 % MOD;
        }

        for (int i = 0; i < n; i ++) {
            int num = s[i] - '0';
            sum[i + 1] = sum[i] + num;
            cnt[i + 1] = cnt[i] + (num > 0);
            nums[i + 1] = (num > 0) ? (1LL * nums[i] * 10 + num) % MOD : nums[i];
        }

        vector<int> res;
        for (const vector<int>& query : queries) {
            int l = query[0], r = query[1] + 1;

            int len = cnt[r] - cnt[l];
            int s = sum[r] - sum[l];
            long long x = (((1LL * nums[r] - 1LL * nums[l] * pow10[len]) % MOD) + MOD) % MOD;

            res.push_back((int)((x * s) % MOD));
        }

        return res;
    }
};
