// Triangle
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        memo.resize(n, {});
        for (int i = 0; i < n; i ++) {
            memo[i].resize(i + 1, INT_MAX);
        }

        return pathHelper(triangle, 0, 0);
    }

private:
    vector<vector<int>> memo;

    int pathHelper(vector<vector<int>>& triangle, int lvl, int pos) {
        int n = triangle.size();
        if (lvl == n) return 0;

        if (memo[lvl][pos] != INT_MAX) return memo[lvl][pos];

        int left = pathHelper(triangle, lvl + 1, pos);
        int right = pathHelper(triangle, lvl + 1, pos + 1);

        return memo[lvl][pos] = triangle[lvl][pos] + min(left, right);
    }
};

// Tabulation
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>());
        for (int i = 0; i < n; i ++) {
            dp[i].resize(i + 1, INT_MAX);
        }

        dp[0][0] = triangle[0][0];
        int minVal = dp[0][0];
        for (int i = 1; i < n; i ++) {
            minVal = INT_MAX;
            for (int j = 0; j < triangle[i].size(); j ++) {
                int tLeft = j > 0 ? dp[i - 1][j - 1] : INT_MAX;
                int tRight = j < i ? dp[i - 1][j] : INT_MAX;
                dp[i][j] = triangle[i][j] + min(tLeft, tRight);
                minVal = min(dp[i][j], minVal);
            }
        }

        return minVal;
    }
};
