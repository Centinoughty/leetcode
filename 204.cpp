// Count Primes
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> mp(n - 2, true);
        for (int i = 0; i < n - 2; i ++) {
            if (mp[i]) {
                int cnt = 2, val = i + 2;
                while (val * cnt < n) {
                    mp[val * cnt - 2] = false;
                    cnt ++;
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < n - 2; i ++) {
            if (mp[i]) cnt ++;
        }

        return cnt;
    }
};
