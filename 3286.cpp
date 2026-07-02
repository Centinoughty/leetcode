// Find a Safe Walk Through a Grid
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();
        vis.resize(m, vector<bool>(n, false));
        memo.resize(m, vector<vector<int>>(n, vector<int>(health + 1, -1)));

        return dfs(grid, 0, 0, health);
    }

private:
    vector<vector<bool>> vis;
    vector<vector<vector<int>>> memo;
    vector<pair<int, int>> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    bool dfs(vector<vector<int>>& grid, int x, int y, int health) {
        int m = grid.size(), n = grid[0].size();
        if (x < 0 || y < 0 || x == m || y == n || vis[x][y]) return false;

        if (grid[x][y] == 1) health --;
        if (health == 0) return false;

        if (memo[x][y][health] != -1) return memo[x][y][health];

        if (x == m - 1 && y == n - 1) return true;

        vis[x][y] = true;
        
        bool res = false;
        for (const auto& [dx, dy] : dirs) {
            int nx = x + dx, ny = y + dy;

            if (dfs(grid, nx, ny, health)) {
                res = true;
                break;
            }
        }

        vis[x][y] = false;
        return memo[x][y][health] = res;
    }
};
