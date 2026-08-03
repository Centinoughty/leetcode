// Stone Game III
// HARD

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        memo.resize(n, INT_MIN);
        int val = gameHelper(stoneValue, 0);

        if (val > 0) {
            return "Alice";
        } else if (val < 0) {
            return "Bob";
        } else {
            return "Tie";
        }
    }

private:
    vector<int> memo;

    int gameHelper(vector<int>& stones, int pos) {
        int n = stones.size();
        if (pos == n) return 0;

        if (memo[pos] != INT_MIN) return memo[pos];

        int a = stones[pos] - gameHelper(stones, pos + 1);
        int b = pos + 1 < n ? stones[pos] + stones[pos + 1] - gameHelper(stones, pos + 2) : INT_MIN;
        int c = pos + 2 < n ? stones[pos] + stones[pos + 1] + stones[pos + 2] - gameHelper(stones, pos + 3) : INT_MIN;

        return memo[pos] = max(a, max(b, c));
    }
};

// Tabulation
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n + 3, 0);

        for (int i = n - 1; i >= 0; i --) {
            int best = INT_MIN, sum = 0;

            for (int j = 0; j < 3 && i + j < n; j ++) {
                sum += stoneValue[i + j];
                best = max(best, sum - dp[i + j + 1]);
            }

            dp[i] = best;
        }

        if (dp[0] > 0) {
            return "Alice";
        } else if (dp[0] < 0) {
            return "Bob";
        } else {
            return "Tie";
        }
    }
};
