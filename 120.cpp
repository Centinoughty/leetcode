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
