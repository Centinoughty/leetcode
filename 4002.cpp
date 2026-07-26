// Count Valid Sequences
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

class Solution {
public:
    int countValidSequences(int n, int k) {
        fact.resize(n + 1, 1);
        invFact.resize(n + 1, 1);

        for (int i = 1; i <= n; i ++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }

        invFact[n] = pow(fact[n], MOD - 2);
        for (int i = n - 1; i >= 0; i --) {
            invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
        }

        int total = nCr(n - 1, k - 1);
        int odd = 0;

        if ((n - k) % 2 == 0) {
            int m = (n - k) / 2;
            odd = nCr(m - 1, k - 1);
        }

        return (total - odd + MOD) % MOD;
    }

private:
    vector<long long> fact, invFact;

    long long pow(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) {
                res = (res * a) % MOD;
            }

            a = (a * a) % MOD;
            b >>= 1;
        }

        return res;
    }

    long long nCr(int n, int r) {
        if (n < 0 || r < 0 || r > n) return 0;
        return (((fact[n] * invFact[r]) % MOD) * invFact[n - r]) % MOD;
    }
};
