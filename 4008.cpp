// Minimum Initial Strength to Defeat all Monsters
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        int n = monsters.size();
        vector<long long> diff(n + 1, 0);

        for (const vector<int>& boost : boosts) {
            int l = boost[0], r = boost[1], w = boost[2];

            diff[l] += w;
            diff[r + 1] -= w;
        }

        for (int i = 1; i < n + 1; i ++) {
            diff[i] += diff[i - 1];
        }

        long long l = 0, r = accumulate(monsters.begin(), monsters.end(), 0LL);

        long long res = 0;
        while (l <= r) {
            long long mid = l - (l - r) / 2;

            int i = 0;
            long long score = mid;
            while (i < n) {
                if (score + diff[i] >= monsters[i]) {
                    score = max(0LL, score - monsters[i]);
                } else break;

                i ++;
            }
            
            if (i == n) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return res;
    }
};
