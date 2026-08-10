// Stone Game IV
// HARD

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool winnerSquareGame(int n) {
        memo.resize(n + 1, -1);
        return gameHelper(n);
    }

private:
    vector<int> memo;

    bool gameHelper(int n) {
        if (n == 0) return 0;

        if (memo[n] != -1) return memo[n];
        
        bool res = false;

        int cnt = 1;
        while (1LL * n - 1LL * cnt * cnt >= 0) {
            res |= !gameHelper(n - cnt * cnt);
            if (res) break;
            cnt ++;
        }

        return memo[n] = res;
    }
};
