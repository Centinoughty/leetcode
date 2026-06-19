// Minimum Cost to Cut a Stick
// HARD

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());

        newCuts.push_back(0);
        for (const int& cut : cuts) {
            newCuts.push_back(cut);
        }

        newCuts.push_back(n);
        int m = newCuts.size();
        memo.resize(m + 1, vector<int>(m + 1, -1));

        return costHelper(0, m - 1);
    }

private:
    vector<int> newCuts;
    vector<vector<int>> memo;

    int costHelper(int l, int r) {
        if (memo[l][r] != -1) return memo[l][r];

        if (r - l == 1) return 0;

        int res = INT_MAX;
        for (int mid = l + 1; mid < r; mid ++) {
            int cost = costHelper(l, mid) + costHelper(mid, r) + newCuts[r] - newCuts[l];
            res = min(res, cost);
        }

        return memo[l][r] = res;
    }
};

// Tabulation
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());

        vector<int> newCuts;
        newCuts.push_back(0);
        for (const int& cut : cuts) {
            newCuts.push_back(cut);
        }

        newCuts.push_back(n);

        int m = newCuts.size();
        vector<vector<int>> dp(m + 1, vector<int>(m + 1, 0));
        for (int len = 2; len < m; len ++) {
            for (int i = 0; i + len < m; i ++) {
                int j = i + len;
                int res = INT_MAX;
                for (int mid = i + 1; mid < j; mid ++) {
                    int cost = dp[i][mid] + dp[mid][j] + newCuts[j] - newCuts[i];
                    res = min(res, cost);
                }

                if (res == INT_MAX) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = res;
                }
            }
        }

        return dp[0][m - 1];
    }
};
