// Stone Game II
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        memo.resize(n, vector<int>(2 * n + 1, -1));

        return gameHelper(piles, 0, 1);
    }

private:
    vector<vector<int>> memo;

    int gameHelper(vector<int>& piles, int pos, int m) {
        int n = piles.size();
        if (pos >= n) return 0;

        if (memo[pos][m] != -1) return memo[pos][m];

        int total = accumulate(piles.begin() + pos, piles.end(), 0);

        int res = 0, currSum = 0;
        for (int k = 1; k <= 2 * m && pos + k <= n; k ++) {
            currSum += piles[pos + k - 1];
            int opponent = gameHelper(piles, pos + k, max(m, k));
            int curr = total - opponent;
            res = max(res, curr);
        }

        return memo[pos][m] = res;
    }
};
