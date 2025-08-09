// Minimum falling path sum
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        dp = vector<vector<int>>(m, vector<int>(n, INT_MAX));
        int minSum = INT_MAX;
        for (int i = 0; i < n; i ++) {
            minSum = min(minSum, fallingPath(matrix, 0, i));
        }

        return minSum;
    }

private:
    vector<vector<int>> dp;

    int fallingPath(vector<vector<int>>& matrix, int i, int j) {
        if (i == matrix.size() || j < 0 || j == matrix[0].size()) {
            return INT_MAX;
        }

        if (dp[i][j] != INT_MAX) return dp[i][j];

        int b1 = fallingPath(matrix, i + 1, j - 1);
        int b2 = fallingPath(matrix, i + 1, j);
        int b3 = fallingPath(matrix, i + 1, j + 1);
        int minPath = min(b1, min(b2, b3));
        int minPathVal = minPath == INT_MAX ? 0 : minPath;

        dp[i][j] = matrix[i][j] + minPathVal;
        return dp[i][j];
    }
};
