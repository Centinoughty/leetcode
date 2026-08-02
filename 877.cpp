// Stone Game
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        memo.resize(n, vector<int>(n, -1));
        return gameHelper(piles, 0, n - 1) > 0;
    }

private:
    vector<vector<int>> memo;

    int gameHelper(vector<int>& piles, int l, int r) {
        if (l == r) return piles[l];

        if (memo[l][r] != -1) return memo[l][r];

        return memo[l][r] = max(piles[l] - gameHelper(piles, l + 1, r), piles[r] - gameHelper(piles, l, r - 1));
    }
};
